package main

import "fmt"

func main() {
	joe := make([][]int, 3)

	for i := 0; i < 3; i++ {
		joe[i] = make([]int, 5+i)
	}

	fmt.Printf("%#v", joe)
}
