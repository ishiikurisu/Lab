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
			go func(s string) {
				process(s)
				wg.Done()
			}(fmt.Sprintf("%s/%s", source, it.Name()))
		}
	}
	wg.Wait()
	fmt.Println("...")
}

func process(source string) {
	files, _ := ioutil.ReadDir(source)
	for _, file := range files {
		fileName := fmt.Sprintf("%s/%s", source, file.Name())
		if match(file.Name(), "inventory") {
			// TODO Convert inventory file
			fmt.Printf("%s is an inventory!\n", fileName)
		} else if match(file.Name(), "results") {
			// TODO Convert results files
			fmt.Printf("%s is a results file!\n", fileName)
		} else {
			fmt.Printf("%s is nothing special!\n", fileName)
		}
	}
}

func match(s, t string) bool {
	limit := min(len(s), len(t))
	flag := true
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
