package main

import "fmt"

func main() {
	var number int16 = 25
	haystack := "hello joe frank"


	for i, hay := range haystack {
		fmt.Printf("%2d. %c\n", i, hay)
	}

	var i uint = 0
	for (number >> i) != 0 {
		fmt.Printf("- %v\n", (number >> i) & 0x1)
		i++
	}
}