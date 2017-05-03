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
			where := fmt.Sprintf("%s/%s", source, it.Name())
			go process(where, &wg)
		}
	}
	wg.Wait()
	fmt.Println("...")
}

func process(source string, wg *sync.WaitGroup) {
	defer wg.Done()
	fmt.Println(source)
}
