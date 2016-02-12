package edfp

import "os"
import "fmt"

func ReadFile(input string) map[string]string {
    inlet, _ := os.Open(input)
    specsList := GetSpecsList()
    specsLength := GetSpecsLength()

    defer inlet.Close()
    header := ReadHeader(inlet, specsList, specsLength)

    return header
}

func ReadHeader(inlet *os.File, specsList []string, specslength map[string]int) map[string]string {
    header := make(map[string]string)
    numberSignals := 0
    index := 0

    for index < len(specsList) {
        spec := specsList[index]

        if spec == "label" {
            break
        } else {
            data := make([]byte, specslength[spec])
            n, _ := inlet.Read(data)
            header[spec] = string(data[:n])
        }

        index++
    }

    fmt.Sscanf(header["numbersignals"], "%d", &numberSignals)
    for index = index; index < len(specsList) ; index++ {
        spec := specsList[index]
        data := make([]byte, specslength[spec] * numberSignals)
        n, _ := inlet.Read(data)
        header[spec] = string(data[:n])
    }

    return header
}
