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
func BeginStopwatch() map[string][]float64 {
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
 * @param analysis the analysis structure, as given by BeginStopwatch()
 * @return the updated analysis structure
 */
func UpdateStopwatch(analysis map[string][]float64,
                     tag string,
                     data []float64) map[string][]float64 {
    analysis[tag] = data
    return analysis
}

/**
 * Turn the analysis structure into a CSV table
 * @param analysis the structure, as given by UpdateStopwatch()
 * @return a string containing the CSV table ready to be written in a file
 */
func FormatStopwatch(analysis map[string][]float64, ids map[string]string) string {
    outlet := "File\tSubject\tSession\tEvents\n"

    for file, events := range analysis {
        line := fmt.Sprintf("%s\t%s", file, ids[file])
        for _, event := range events {
            line += replaceInString(fmt.Sprintf("\t%.3f", event / 1000), '.', ',')
        }
        outlet += line + "\n"
    }

    return outlet
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
