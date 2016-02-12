package main

import "./edfp"
import "os"
import "fmt"

func main() {
    input := os.Args[1]
    header, records := edfp.ReadFile(input)

    fmt.Printf("input: %v\n", input)
    fmt.Printf("specs: %#v %#v\n", header, records)
}
