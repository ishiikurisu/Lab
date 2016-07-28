package main

import "os"
import "fmt"
import "strings"
import "./edf"
// import "./sst"

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
        // lines[0] = createFirstLine

        // saving data
        linesToFile(outlet + fmt.Sprintf("%v", firstMoment), lines)
    }
}

func createOutlet(inlet string) string {
    return inlet + ".csv"
}

func getFirstMoment(header map[string]string) int {
    // TODO Extract first moment
    return 0
}

func linesToFile(output string, data []string) {
    file, _ := os.Create(output)

    defer file.Close()
    for _, line := range data {
        file.WriteString(line + "\n")
    }
}
