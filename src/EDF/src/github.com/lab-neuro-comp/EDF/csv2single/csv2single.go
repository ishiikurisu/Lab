package main

import "github.com/ishiikurisu/edf"
import "os"

func main() {
	edf.Csv2Single(os.Args[1])
}
