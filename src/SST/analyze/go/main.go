package main

import "os"
import "fmt"
import "./sst"
import "io/ioutil"

func main() {
	source := "."

	if len(os.Args) > 1 {
		source = os.Args[1]
	}

	source += "/"
	stuff, shit := ioutil.ReadDir(source)
	if shit != nil {
		panic(shit)
	}

	for _, file := range stuff {
		if sst.ValidFile(file.Name()) {
			path := source + file.Name()
			raw := sst.Read(path)
			data := sst.AnalyzeSingle(raw)
			sst.WriteSingle(data)
		}
	}
	
}
