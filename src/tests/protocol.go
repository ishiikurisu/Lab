package main

import (
    "fmt"
    "bufio"
    "os"
    "strconv"
)

func htmlCode(point rune) string {
    code := strconv.Itoa(int(point))

    switch point {
    case 'á':
        code = "&aacute;"
        break
    case 'é':
        code = "&eacute;"
        break
    case 'í':
        code = "&iacute;"
        break
    case 'ó':
        code = "&oacute;"
        break
    case 'ú':
        code = "&uacute;"
        break
    case 'â':
        code = "&acirc;"
        break
    case 'ê':
        code = "&ecirc;"
        break
    case 'ô':
        code = "&ocirc;"
        break
    case 'ç':
        code = "&ccedil;"
        break
    case 'ã':
        code = "&atilde;"
    case 'õ':
        code = "&otilde;"
        break
    case 'à':
        code = "&agrave;"
        break
    }

    return code
}

func readLines(path string) ([]string, error) {
    file, err := os.Open(path)
    if err != nil {
        return nil, err
    }
    defer file.Close()

    var lines []string
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        lines = append(lines, scanner.Text())
    }
    return lines, scanner.Err()
}

func translate(inlet string) string {
    outlet := ""

    for _, point := range inlet {
        outlet += htmlCode(point)
    }

    return outlet
}

func main() {
    content, err := readLines(os.Args[1])

    if err == nil {
        return
    }

    for _, line := range content {
        fmt.Printf("%v\n", translate(line))
    }
}
