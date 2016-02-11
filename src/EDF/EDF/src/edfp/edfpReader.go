package edfp

// #include <stdlib.h>
import "C"
import "os"

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

    for i := 0; i < len(specsList); i++ {
        spec := specsList[i]

        if spec == "label" {
            break
        } else {
            data := make([]byte, specslength[spec])
            n, _ := inlet.Read(data)
            header[spec] = string(data[:n])
        }
    }

    for ; i < len(specsList) ; i++ {
        spec = specs[List]
        data := make([]byte, specslength[spec]) // GO ON DOING THIS LATER
    }

    return header
}
