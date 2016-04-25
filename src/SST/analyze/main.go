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
	files, _ := ioutil.ReadDir(source)
	outlet, _ := os.Create(source + "sst.csv")
	defer outlet.Close()

	analysis := sst.BeginAnalysis()
	sst.Write(outlet, sst.BeginCSV())
	for _, file := range files {
		if sst.ValidFile(file.Name()) {
			data := sst.AnalyzeSingle(sst.Read(source + file.Name()))
			analysis = sst.UpdateAnalysis(data, analysis)
			sst.Write(outlet, fmt.Sprintf("%s%s\n", file.Name(),
				                                    sst.FormatSingleCSV(data)))
		}
	}
	sst.Write(outlet, sst.FormatMultipleCSV(analysis))
}
