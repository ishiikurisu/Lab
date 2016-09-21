package main

import "os"
import "fmt"
import "github.com/ishiikurisu/edf"

func main() {
	header, records := edf.ReadFile(os.Args[1])
	notes := edf.WriteNotes(header, records)
	fmt.Printf("%v", notes)
}
