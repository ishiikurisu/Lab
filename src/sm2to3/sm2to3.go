package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"sync"
)

func main() {
	var wg sync.WaitGroup
	var source string

	if len(os.Args) > 1 {
		source = os.Args[1]
	} else {
		source = "."
	}

	fmt.Println("---")
	stuff, _ := ioutil.ReadDir(source)
	for _, it := range stuff {
		if it.IsDir() {
			wg.Add(1)
			go func(s string, wg *sync.WaitGroup) {
				process(s)
				wg.Done()
			}(fmt.Sprintf("%s/%s", source, it.Name()), &wg)
		}
	}
	wg.Wait()
	fmt.Println("...")
}

func process(source string) {
	files, _ := ioutil.ReadDir(source)
	for _, file := range files {
		fileName := fmt.Sprintf("%s/%s", source, file.Name())
		if match(file.Name(), "inventory.txt") {
			// TODO Convert inventory file
			convertInventory(fileName)
		} else if match(file.Name(), "results") {
			// TODO Convert results files
			fmt.Printf("%s is a results file!\n", fileName)
		} else {
			fmt.Printf("%s is nothing special!\n", fileName)
		}
	}
}

func convertInventory(input string) string {
	output := changeExtension(input, "csv")
	inlet, _ := os.Open(input)
	outlet, _ := os.Create(output)
	defer inlet.Close()
	defer outlet.Close()

	line := ReadLine(inlet)
	fmt.Printf("%s: %s\n", input, line)

	return output
}

func match(s, t string) bool {
	limit := min(len(s), len(t))
	flag := true

	if limit == 0 {
		return false
	}

	for i := 0; i < limit; i++ {
		if s[i] != t[i] {
			flag = false
		}
	}
	return flag
}

func min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func changeExtension(inlet, ext string) string {
	i := len(inlet) -1
	for i = i; inlet[i] != '.';  i-- {

	}
	outlet := inlet[:i] + "." + ext
	return outlet
}

// Reads a whole line from the file in pointer.
func ReadLine(inlet *os.File) string {
	stuff := ""

	for data := ReadChar(inlet); data != '\n'; data = ReadChar(inlet) {
		stuff += string(data)
	}

	return stuff
}

// Reads a single char from the file pointer.
func ReadChar(inlet *os.File) byte {
	data := make([]byte, 2)
	_, shit := inlet.Read(data)

	if shit != nil {
		return '\n'
	} else {
		return data[0]
	}
}
