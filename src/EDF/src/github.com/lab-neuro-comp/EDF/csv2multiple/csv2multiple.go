package main

import "github.com/ishiikurisu/edf"
import "os"

func main() {
    edf.Csv2Multiple(os.Args[1])
}
