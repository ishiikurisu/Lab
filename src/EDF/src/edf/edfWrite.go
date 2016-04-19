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
 * Translates the data to the *.csv format into the standard output.
 * @param header a map containg the EDF header data as strings.
 * @param records the data records as 16bit integers.
 */
func WriteCSV(header map[string]string, records [][]int16) {
	numberSignals := getNumberSignals(header)
	convertionFactor := setConvertionFactor(header)

	// writing header...
	fmt.Printf("title:%s,", header["recording"])
	fmt.Printf("recorded:%s %s,", header["startdate"], header["starttime"])
	fmt.Printf("sampling:128,")
	fmt.Printf("subject:%s,", header["patient"])
	fmt.Printf("labels:%v,", getLabels(header))
	fmt.Printf("chan:%s,", header["numbersignals"])
	fmt.Printf("units:uV\n")

	// writing data records...
	limit := len(records[0])
	for j := 0; j < limit; j++ {
		for i := 0; i < numberSignals; i++ {
			data := float64(records[i][j]) * convertionFactor[i]

			if i == 0 {
				fmt.Printf("%f", data)
			} else {
				fmt.Printf(", %f", data)
			}
		}
		fmt.Printf("\n")
	}
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
// func WriteNotes(header map[string]string, records [][]int16) {
// 	annotations := records[getAnnotationsChannel(header)

// }

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
		if match(label, "EDF annotations") {
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

