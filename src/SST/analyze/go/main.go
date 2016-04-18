package main

import "fmt"
import "os"
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

	analysis := sst.BeginAnalysis()
	sst.Write(nil, sst.BeginCSV())
	for _, file := range stuff {
		if sst.ValidFile(file.Name()) {
			data := sst.AnalyzeSingle(sst.Read(source + file.Name()))
			analysis = sst.UpdateAnalysis(data, analysis)
			sst.Write(nil, fmt.Sprintf("%s%s\n", file.Name(),
				                                   sst.FormatSingleCSV(data)))
		}
	}
	sst.Write(nil, sst.FormatMultipleCSV(analysis))
}
