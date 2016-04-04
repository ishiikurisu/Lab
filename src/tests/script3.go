package main

import "fmt"
import "io/ioutil"

func main() {
	files, _ := ioutil.ReadDir("data")
	for _, file := range files {
		fmt.Println(file.Name())	
	}
	
}