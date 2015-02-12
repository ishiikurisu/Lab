package main

import "./edfp"
import "os"
import "fmt"

func main() {
    input := os.Args[1]

    fmt.Printf("input: %v\n", input)
    fmt.Printf("specs: %#v\n", edfp.ReadFile(input))
}
