package main

import "os"
import "fmt"
import "./edf"

func main() {
	header, records := edf.ReadFile(os.Args[1])
	fmt.Println(edf.WriteASCII(header, records))
}