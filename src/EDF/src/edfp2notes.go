package main

import "os"
import "fmt"
import "./edf"

func main() {
	header, records := edf.ReadFile(os.Args[1])
	notes := edf.WriteNotes(header, records)
	fmt.Printf("%v", notes)
}