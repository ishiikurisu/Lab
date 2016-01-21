package main

// #include "csv2ascii.h"
import "C"
import "os"
import "./csv2ascii"

func getOutput(input string) string {
	return C.GoString(C.get_output(C.CString(input)))
}

func main() {
	inputFile := os.Args[1]
	outputFile := getOutput(inputFile)
	csv2ascii.csv2single(inputFile, outputFile)
}
