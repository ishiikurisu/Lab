package main

import "os"
import "fmt"
import "./sst"

func main() {
	fmt.Printf("%#v\n", sst.Read(os.Args[1]))
}