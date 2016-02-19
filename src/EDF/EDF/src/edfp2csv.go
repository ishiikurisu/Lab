package main

import "./edfp"
import "os"

func main() {
    input := os.Args[1]
    header, records := edfp.ReadFile(input)
    edfp.WriteCSV(header, records)
}
