package edfp

// #include <stdlib.h>
import "C"
    import "os"

func ReadFile(input string) map[string]string {
    inlet, _ := os.Open(input)
    specs := GetSpecs()

    defer inlet.Close()
    header := ReadHeader(inlet, specs)

    return header
}

func ReadHeader(inlet *os.File, specs map[string]int) map[string]string {
    header := make(map[string]string)

    for key, value := range specs {
        if key == "label" {
            break
        } else {
            data := make([]byte, value)
            n, _ := inlet.Read(data)
            header[key] = string(data[:n])
        }
    }

    return header
}
