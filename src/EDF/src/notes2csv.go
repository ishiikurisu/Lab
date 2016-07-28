package main

import "os"
import "fmt"
import "strings"
import "strconv"
import "./edf"
import "./sst"

func main() {
    for i := 1; i < len(os.Args); i++ {
        // Setting up environment
        inlet := os.Args[i]
        outlet := createOutlet(inlet)
        header, records := edf.ReadFile(inlet)
        notes := strings.Split(edf.WriteNotes(header, records), "\n")
        lines := make([]string, len(notes) + 1)
        firstMoment := getFirstMoment(header)

        // populating lines to file
        lines[0] = createFirstLine(inlet, firstMoment)
        for i, note := range notes {
            lines[i+1] = createIthLine(inlet, note, firstMoment)
        }

        // saving data
        linesToFile(outlet, lines)
    }
}

func createOutlet(inlet string) string {
    return inlet + ".csv"
}

func getFirstMoment(header map[string]string) int {
    startDate := header["startdate"]
    startTime := header["starttime"]
    dateRaw := strings.Split(startDate, ".")
    timeRaw := strings.Split(startTime, ".")
    timestamp := fmt.Sprintf("20%v-%v-%vT%v:%v:%vZ", dateRaw[2], dateRaw[1], dateRaw[0],
                                                     timeRaw[0], timeRaw[1], timeRaw[2])
    result := sst.ConvertToUnixTime(timestamp)
    return result
}

func createFirstLine(inlet string, moment int) string {
    return fmt.Sprintf("%v\tComeço da gravação\t%v\n", inlet, sst.ConvertToTimeStamp(moment))
}

func createIthLine(inlet string, note string, start int) string {
    raw := strings.Split(note, " ")
    outlet := ""

    if len(raw) > 2 {
        // Getting annotation
        annotation := raw[2]

        // Getting moment
        number, _ := strconv.ParseFloat(raw[0][1:], 32)
        unixtime := start + int(number - 1)
        moment := sst.ConvertToTimeStamp(unixtime)

        // Building outlet
        outlet = fmt.Sprintf("%v\t%v\t%v\n", inlet, annotation, moment)
    }

    return outlet
}

func linesToFile(output string, data []string) {
    file, _ := os.Create(output)

    defer file.Close()
    for _, line := range data {
        file.WriteString(line)
    }
}
