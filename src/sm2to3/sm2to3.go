package main

import (
	"fmt"
	"io/ioutil"
	"os"
	"sync"
	"strings"
)

func main() {
	var wg sync.WaitGroup
	var source string

	if len(os.Args) > 1 {
		source = os.Args[1]
	} else {
		source = "."
	}

	stuff, _ := ioutil.ReadDir(source)
	for _, it := range stuff {
		if it.IsDir() {
			wg.Add(1)
			go func(s string, wg *sync.WaitGroup) {
				process(s)
				wg.Done()
			}(fmt.Sprintf("%s/%s", source, it.Name()), &wg)
		} else if match(it.Name(), "kinds.txt") {
			wg.Add(1)
			go func(s string, wg *sync.WaitGroup) {
				kindify(s)
				wg.Done()
			}(fmt.Sprintf("%s/%s", source, it.Name()), &wg)
		}
	}
	wg.Wait()
}

func process(source string) {
	files, _ := ioutil.ReadDir(source)
	for _, file := range files {
		fileName := fmt.Sprintf("%s/%s", source, file.Name())
		if match(file.Name(), "inventory.txt") {
			convertInventory(fileName)
		} else if match(file.Name(), "results") {
			convertResults(fileName)
		} else {
		}
	}
}

func convertInventory(input string) string {
	output := changeExtension(input, "csv")
	outlet, _ := os.Create(output)
	defer outlet.Close()

	// Loading file
	stuff, _ := ioutil.ReadFile(input)
	lines := strings.Split(string(stuff), "\n")

	// Analysing first line
	size := 0
	firstLine := lines[0]
	for offset := 0; size == 0; offset++ {
		fmt.Sscanf(firstLine[offset:], "%d", &size)
	}

	// Building table
	for i, line := range lines[1:] {
		if (i % (size+1) == 0) && (i > 1) {
			fmt.Fprintf(outlet, "\n")
		}
		fmt.Fprintf(outlet, "%s\t", strings.TrimSpace(line))
	}

	return output
}

func convertResults(input string) string {
	output := changeExtension(input, "csv")
	outlet, _ := os.Create(output)
	defer outlet.Close()

	// Loading file
	contents, _ := ioutil.ReadFile(input)
	lines := strings.Split(string(contents), "\n")

	// Converting lines to a table
	for _, line := range lines {
		if len(line) == 0 {
			continue
		}
		stuff := strings.Split(line, " ")
		result := strings.Join(stuff[2:], " ")
		fmt.Fprintf(outlet, "%s\t%s\t%s\n", stuff[0], stuff[1], result)
	}

	return output
}

func kindify(input string) {
	output := changeExtension(input, "csv")
	outlet, _ := os.Create(output)
	defer outlet.Close()

	// Loading file
	contents, _ := ioutil.ReadFile(input)
	lines := strings.Split(string(contents), "\n")

	// Converting lines to a table
	for _, line := range lines {
		// FIXME: This line produces some weird stuff
		if len(line) == 0 {
			continue
		}
		stuff := strings.Split(line, " ")
		result := strings.Join(stuff[1:], " ")
		fmt.Fprintf(outlet, "%s\t%s\t%s\n", stuff[0], result)
	}
}

/*********
 * TOOLS *
 *********/

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
