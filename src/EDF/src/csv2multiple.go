package main

// #include "C/buffer.h"
// #include "C/buffer.h"
// #include "csv2ascii.h"
import "C"
import "os"

func main() {
    C.csv2multiple(C.CString(os.Args[1]))
}
