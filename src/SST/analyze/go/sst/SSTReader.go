package sst

import "os"

/**
 * Reads the choosen file and translates it into a collection of arrays
 * @param input the name of the input file
 * @return a map relating the specied information and the 
 */
func Read(input string) map[string]int {
	inlet, _ := os.Open(input)
	header := ReadHeader(inlet)

	defer inlet.Close()
	return header
}

func ReadHeader(inlet *os.File) map[string]int {
	ReadLine(inlet)
	rawData := ReadLine(inlet)
	header := make(map[string]int)
	stuff := Split(rawData, '\t')

	header["raw"] = len(rawData)
	header["stuff"] = len(stuff)

	return header
}