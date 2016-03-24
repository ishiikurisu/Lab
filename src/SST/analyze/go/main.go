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

	for _, file := range stuff {
		analysis := sst.BeginAnalysis()
		if sst.ValidFile(file.Name()) {
			data := sst.AnalyzeSingle(sst.Read(source + file.Name()))
			analysis = sst.UpdateAnalysis(data, analysis)
			sst.WriteSingle(nil, fmt.Sprintf("# %s\n%s\n", file.Name(),
				                                           sst.FormatOutput(data)))
		}
		sst.WriteSingle(nil, sst.FormatOutput(sst.EndAnalysis(analysis)))
	}
	
}
