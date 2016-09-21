package edf

// #include "C/oa.h"
// #include "C/buffer.h"
// #include "C/csv2ascii.h"
import "C"

func Csv2single(inlet string) {
    C.csv2single(C.CString(inlet))
}
