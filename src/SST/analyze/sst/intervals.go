package sst

import "os"
import "fmt"
import "sort"

/*****************
* MAIN FUNCTIONS *
******************/

/**
 *  Creates an analysis structure for extracting intervals
 * @return a map relating the file name and the intervals in seconds
*/
func BeginClock() map[string][]float64 {
    return make(map[string][]float64)
}

/**
 * Reads every line in a file and extract
 * @param input the file name as a string
 * @return the intervals in the file, sorted
 */
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

/**
 * Updates the analysis structure by relating the file name to its intervals
 * @param data the array of intervals
 * @param tag the file name
 * @param analysis the analysis structure, as given by BeginClock()
 * @return the updated analysis structure
 */
func UpdateClock(data []float64,
                 tag string,
                 analysis map[string][]float64) map[string][]float64 {
    analysis[tag] = data
    return analysis
}

/**
 * Turn the analysis structure into a CSV table
 * @param analysis the structure, as given by UpdateClock()
 * @return a string containing the CSV table ready to be written in a file
 */
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
