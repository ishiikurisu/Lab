package sst

import "os"
import "fmt"
import "sort"

/*****************
* MAIN FUNCTIONS *
******************/

func BeginClock() map[string][]float64 {
    return make(map[string][]float64)
}

func ExtractIntervals(input string) []float64 {
    inlet, _ := os.Open(input)
    outlet := make([]float64, 0)

    // read variables
    defer inlet.Close()
    header := ReadHeader(inlet, getOnSetTags())
    records := ReadRecords(inlet, header)

    // convert them
    for _, record := range records {
        for _, raw := range record {
            data := ParseFloat64(raw)
            if data > 0 {
                outlet = append(outlet, data)
            }
        }
    }

    sort.Float64s(outlet)
    return outlet
}

func UpdateClock(data []float64,
                 tag string,
                 analysis map[string][]float64) map[string][]float64 {
    analysis[tag] = data
    return analysis
}

func FormatClock(analysis map[string][]float64) string {
    outlet := ""
    howManyFiles := len(analysis)
    files := make([]string, howManyFiles)

    // set files
    i := 0
    for key, _ := range analysis {
        files[i] = key
        outlet = fmt.Sprintf("%s%s\t", outlet, files[i])
        i++
    }

    // write durations
    limit := len(analysis[files[0]])
    for j := 0; j < limit; j++ {
        line := ""
        for i = 0; i < howManyFiles; i++ {
            line = fmt.Sprintf("%s%.3f\t", line, analysis[files[i]][j] / 1000)
        }
        outlet = fmt.Sprintf("%s\n%s", outlet, line)
    }

    return fmt.Sprintf("%s\n", outlet)
}

/*********************
* AUXILIAR FUNCTIONS *
*********************/
func getOnSetTags() []string {
    return []string {
        "PressStimulus.OnsetTime",
        "VisualStimulus.OnsetTime",
    }
}
