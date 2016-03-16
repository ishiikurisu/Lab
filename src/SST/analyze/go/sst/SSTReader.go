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

/**
 * Gets the indexes of the needed fields from the header
 * @param inlet the pointer to the specified file
 * @return a map relating the indexes and the fields
 */
func ReadHeader(inlet *os.File) map[string]int {
	ReadLine(inlet)
	rawData := ReadLine(inlet)
	header := make(map[string]int)
	stuff := Split(rawData, '\t')
	needed := GetNeededVariables()

	header["raw"] = len(rawData)
	header["stuff"] = len(stuff)
	for i, it := range needed {
		fmt.Printf("%d. %v\n", i, it)
	}

	return header
}