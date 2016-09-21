package main

import "os"
import "fmt"
import "github.com/ishiikurisu/edf"

func main() {
    input := os.Args[1]
    header, records := edf.ReadFile(input)
    fmt.Println(edf.WriteCSV(header, records))
}
