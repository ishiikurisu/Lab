package sst

import "os"
import "fmt"
import "strconv"

func min(a, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func ReadLine(inlet *os.File) string {
	stuff := ""

	for data := ReadChar(inlet); data != '\n'; data = ReadChar(inlet) {
		stuff += string(data)
	}

	return stuff
}

func ReadChar(inlet *os.File) byte {
	data := make([]byte, 2)
	_, shit := inlet.Read(data)

	if shit != nil {
		return '\n'
	} else {
		return data[0]
	}
}

func Split(inlet string, separator byte) []string {
	var outlet []string
	division := ""

	for i := 0; i < len(inlet); i++ {
		if inlet[i] != separator {
			division += string(inlet[i])
		} else {
			outlet = append(outlet, division)
			division = ""
		}
	}

	return outlet
}

func Contains(haystack []string, needle string) bool {
	for _, hay := range haystack {
		if hay == needle {
			return true
		}
	}

	return false
}

func ParseFloat64(inlet string) float64 {
	outlet, shit := strconv.ParseFloat(inlet, 64)
	if shit == nil {
		return outlet
	} else {
		return 0
	}
}

func Debug(x interface{}) {
	fmt.Println(x)
}

func ValidFile(inlet string) bool {
	isTxt := true
	isCsv := true
	txt := ".txt"
	csv := ".csv"

	for i := 1; i <= 4; i++ {
		if inlet[len(inlet)-i] != txt[len(txt)-i] {
			isTxt = false
		}
		if inlet[len(inlet)-i] != csv[len(csv)-i] {
			isCsv = false
		}
	}

	return isTxt || isCsv
}