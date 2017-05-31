package main

import (
	"os"
	"fmt"
)

func main() {
	str := os.Args[1]
	var ut int
	fmt.Sscanf(str, "%d", &ut)
	fmt.Printf("%s = %d\n", str, ut)
}
