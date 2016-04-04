package main

import "fmt"

func sum2(n int) int {
    return n+2
}

func id(n int) int {
    return n
}

func multiply3(n int) int {
    return 3*n
}

func main() {
    inlet := "no way"

    fmt.Scanln(&inlet)
    switch inlet {
    case "hello":
        fmt.Println("how are you?")
    case "bye":
        fmt.Println("See ya :)")
    default:
        fmt.Println("what?")
    }

    op := id
    if len(inlet) > 4 {
        op = multiply3
    }
    fmt.Printf("%#v\n", op(len(inlet)))
}
