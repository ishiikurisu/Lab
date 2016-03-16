package sst

import "os"

func ReadLine(inlet *os.File) string {
	stuff := ""

	for data := ReadChar(inlet); data != '\n'; data = ReadChar(inlet) {
		stuff += string(data)
	}
	
	return stuff
}

func ReadChar(inlet *os.File) byte {
	data := make([]byte, 2)
	inlet.Read(data)
	return data[0]
}

func Split(inlet string, separator byte) []string {
	var outlet []string
	division := ""

	for i := 0; i < len(inlet); i++ {
		if inlet[i] != separator {
			division += string(inlet[i])
		} else {
			outlet = append(outlet, division)
			division = ""
		}
	}

	return outlet
}