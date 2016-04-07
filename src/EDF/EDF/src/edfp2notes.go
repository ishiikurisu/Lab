package main

import "fmt"
import "os"
import "./edf"

func main() {
	var numbersignals, index int
	header, _ := edf.ReadFile(os.Args[1])
	fmt.Sscanf(header["numbersignals"], "%d", &numbersignals)
	labels := separateString(header["label"], numbersignals)

	for i, label := range labels {
		if match(label, "EDF Annotations") {
			index = i
		}
	}
	
	fmt.Println(labels[index])
	// TODO: Translate this channel into an annotations file
}

func separateString(stuff string, howMany int) []string {
	bit := len(stuff) / howMany
    outlet := make([]string, howMany)

    for i := 0; i < howMany; i++ {
    	outlet[i] = stuff[bit*i:bit*(i+1)]
    }

    return outlet
}

func match(a, b string) bool {
	result := true
	limit := min(len(a), len(b))

	for i := 0; i < limit && result; i++ {
		if a[i] != b[i] {
			result = false
		}
	}

	return result
}

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}