package main

import "github.com/ishiikurisu/edf"
import "os"

func main() {
	edf.Csv2single(os.Args[1])
}
