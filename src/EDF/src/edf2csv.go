package main

import "./edf"
import "os"

func main() {
    input := os.Args[1]
    header, records := edf.ReadFile(input)
    edf.WriteCSV(header, records)
}