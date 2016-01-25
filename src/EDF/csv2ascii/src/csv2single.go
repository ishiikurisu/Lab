package main

// #include "C/oa.h"
// #include ""
// #include "csv2ascii.h"
import "C"
import "os"

func main() {
	C.csv2single(C.CString(os.Args[1]))
}
