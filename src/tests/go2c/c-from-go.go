package main

// #include "cfromgo.h"
import "C"
import "fmt"

func DoubleMe(x int) int {
    return int(C.double_me(C.int(x)))
}

func main() {
    fmt.Printf("double_me(%d) == %d\n", 42, DoubleMe(42));
}
