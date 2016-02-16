package edfp

import "fmt"

/* --- UTILITY FUNCTIONS --- */
func str2int64(str string) int64 {
	var x int64
	fmt.Sscanf(str, "%d", &x)
	return x
}

func convert(header map[string]string, which int, value int16) float32 {
	dmax := str2int64(header["digitalmaximum"])
	dmin := str2int64(header["digitalminimum"])
	pmax := str2int64(header["physicalmaximum"])
	pmin := str2int64(header["physicalminimum"])
	return 0.0
}

/* --- AUXILIAR FUNCTIONS --- */
func getLabels(header map[string]string) string {
	numberSignals := getNumberSignals(header)
    labels := header["label"]
    ls := len(labels) / numberSignals // labelSize
    outlet := ""

    for i := 0; i < numberSignals; i++ {
    	outlet += labels[ls*i:ls*i+ls] + " "
    }

    return outlet
}

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
 * Translates the data to the *.csv format.
 * @param header a map containg the EDF header data as strings.
 * @param records the data records as 16bit integers.
 */
func WriteCSV(header map[string]string, records [][]int16) {
	numberSignals := getNumberSignals(header)

	// writing header...
	fmt.Printf("title:%s,", header["recording"])
	fmt.Printf("recorded:%s %s,", header["startdate"], header["starttime"])
	fmt.Printf("sampling:200,")
	fmt.Printf("subject:%s,", header["patient"])
	fmt.Printf("labels:%v,", getLabels(header))
	fmt.Printf("chan:%s,", header["numbersignals"])
	fmt.Printf("units:uV\n")

	// writing data records...
	// TODO: create an array of correction factors
	limit := len(records[0])
	for j := 0; j < limit; j++ {
		for i := 0; i < numberSignals; i++ {
			data := convert(header, i, records[i][j])

			if i == 0 {
				fmt.Printf("%f", data)
			} else {
				fmt.Printf(" %f", data)
			}
		}		
		fmt.Printf("\n")
	}
}
