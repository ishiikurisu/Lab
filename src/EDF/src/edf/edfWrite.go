package edf

import "fmt"

/* --- MAIN FUNCTIONS --- */
/**
 * Just writes the read data as Go vars.
 * @param header a map containg the EDF header data as strings.
 * @param records the data records as 16bit integers.
 */
func WriteGo(header map[string]string, records [][]int16) {
	fmt.Printf("header: %#v\n\n", header)
	fmt.Printf("records: %#v\n", records)
}

/**
 * Formats the data to the *.csv format into the standard output.
 * @param header a map containg the EDF header data as strings.
 * @param records the data records as 16bit integers.
 */
func WriteCSV(header map[string]string, records [][]int16) string {
	numberSignals := getNumberSignals(header)
	convertionFactor := setConvertionFactor(header)
	notesChannel := getAnnotationsChannel(header)
	outlet := ""

	// writing header...
	outlet += fmt.Sprintf("title:%s,", header["recording"])
	outlet += fmt.Sprintf("recorded:%s %s,", header["startdate"], header["starttime"])
	outlet += fmt.Sprintf("sampling:128,") // TODO extract sampling rate
	outlet += fmt.Sprintf("subject:%s,", header["patient"])
	outlet += fmt.Sprintf("labels:%v,", getLabels(header))
	outlet += fmt.Sprintf("chan:%s,", header["numbersignals"])
	outlet += fmt.Sprintf("units:uV\n") // TODO extract units 

	// writing data records...
	limit := len(records[0])
	for j := 0; j < limit; j++ {
		for i := 0; i < numberSignals; i++ {
			if i != notesChannel {
				data := float64(records[i][j]) * convertionFactor[i]

				if i == 0 {
					outlet += fmt.Sprintf("%f", data)
				} else {
					outlet += fmt.Sprintf(", %f", data)
				}
			}
		}
		outlet += fmt.Sprintf("\n")
	}

	return outlet
}

/**
 * Translates the data to the *.ascii format into the standard output.
 * @param header a map containg the EDF header data as strings.
 * @param records the data records as 16bit integers.
 */
func WriteASCII(header map[string]string, records [][]int16) {
	numberSignals := getNumberSignals(header)
	convertionFactor := setConvertionFactor(header)
	notesChannel := getAnnotationsChannel(header)
	c := numberSignals
	j := 0

	for c > 0 {
		c = 0

		for i := 0; i < numberSignals; i++ {
			if i != notesChannel {
				c += writeASCIIChannel(records[i], convertionFactor[i], j)
			}
		}

		fmt.Printf("\n")
		j += 1
	}
}

/**
 * Extracts the annoatations channel from the EDF file, if it exists
 * @param header a map containg the EDF header data as strings.
 * @param records the data records as 16bit integers.
 */
func WriteNotes(header map[string]string, records [][]int16) string {
	which := getAnnotationsChannel(header)
	outlet := ""

	if which > 0 && which < len(records) {
		annotations := convertInt16ToByte(records[which])
		outlet += fmt.Sprintf("%s\n", formatAnnotations(annotations))
	}

	return outlet
}

/* --- AUXILIAR FUNCTIONS --- */
func setConvertionFactor(header map[string]string) []float64 {
	ns := getNumberSignals(header)
	factors := make([]float64, ns)
	dmaxs := separateString(header["digitalmaximum"], ns)
	dmins := separateString(header["digitalminimum"], ns)
	pmaxs := separateString(header["physicalmaximum"], ns)
	pmins := separateString(header["physicalminimum"], ns)

	for i := 0; i < ns; i++ {
		dmax := str2int64(dmaxs[i])
		dmin := str2int64(dmins[i])
		pmax := str2int64(pmaxs[i])
		pmin := str2int64(pmins[i])
		dig := float64(dmax-dmin)
		phi := float64(pmax-pmin)
		factors[i] = dig/phi;
	}

	return factors
}

func getLabels(header map[string]string) string {
	numberSignals := getNumberSignals(header)
	labels := separateString(header["label"], numberSignals)
    outlet := labels[0]

    for i := 1; i < numberSignals; i++ {
    	outlet += " " + labels[i]
    }

    return outlet
}

func getAnnotationsChannel(header map[string]string) int {
	result := -1
	labels := separateString(header["label"], getNumberSignals(header))

	for i, label := range labels {
		if match(label, "EDF Annotations") {
			result = i
		}
	}

	return result
}

/* returns false when it can't write anymore */
func writeASCIIChannel(record []int16, convertionFactor float64, j int) int {
	flag := 1

	if j < len(record) {
		fmt.Printf("%f ", float64(record[j]) * convertionFactor)
	} else {
		fmt.Printf("0 ")
		flag = 0
	}

	return flag
}

/* format annotations to human-readable text */
func formatAnnotations(raw []byte) string {
	return formatAnnotationsFeedback(0, raw, false, "")
}
func formatAnnotationsFeedback(index int, 
	                           raw []byte, 
	                           inside bool, 
	                           box string) string {
	if index == len(raw) { 
		return box
	} else if inside {
		if raw[index] == 0 {
			return formatAnnotationsFeedback(index + 1, 
				                             raw, 
				                             false, 
				                             box + fmt.Sprintf("\n"))
		} else {
			if raw[index] == 20 || raw[index] == 21 { raw[index] = ' ' }
			return formatAnnotationsFeedback(index + 1, 
				                             raw, 
				                             inside, 
				                             box + fmt.Sprintf("%c", raw[index]))
		}
	} else if raw[index] == '+' || raw[index] == '-' {
		return formatAnnotationsFeedback(index + 1, 
				                         raw, 
				                         true, 
				                         box + string(raw[index]))
	} else {
		return formatAnnotationsFeedback(index+1, raw, inside, box)
	}
}