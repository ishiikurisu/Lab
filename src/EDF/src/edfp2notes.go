package main

import "os"
import "./edf"

func main() {
	header, records := edf.ReadFile(os.Args[1])
	edf.WriteNotes(header, records)
}