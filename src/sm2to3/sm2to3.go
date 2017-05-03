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
	fmt.Println(source)
}
