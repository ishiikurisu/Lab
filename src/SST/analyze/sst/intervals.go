package sst

import "os"

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

    return outlet
}

func UpdateClock(data []float64,
                 tag string,
                 analysis map[string][]float64) map[string][]float64 {
    analysis[tag] = data
    return analysis
}

func FormatClock(analysis map[string][]float64) string {

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
