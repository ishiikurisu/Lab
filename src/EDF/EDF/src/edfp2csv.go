package main

// #include "edfp.hpp"
import "C"
import "os"

func main() {
	var edfp C.edfp

	edfp.read_file(C.CString(os.Args[1]))
	edfp.csv()
}
