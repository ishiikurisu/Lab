package main

import "fmt"
import "os"
import "./edf"

func main() {
	header, _ := edf.ReadFile(os.Args[1])
	fmt.Println("%#v", header)
}