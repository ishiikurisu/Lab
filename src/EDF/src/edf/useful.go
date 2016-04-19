package edf

import "fmt"

func separateString(stuff string, howMany int) []string {
	bit := len(stuff) / howMany
    outlet := make([]string, howMany)

    for i := 0; i < howMany; i++ {
    	outlet[i] = stuff[bit*i:bit*(i+1)]
    }

    return outlet
}

func append(original, to_append []int16) []int16 {
    lo := len(original)
    lt := len(to_append)
    outlet := make([]int16, lo + lt)

    for o := 0; o < lo; o++ {
        outlet[o] = original[o]
    }
    for t := 0; t < lt; t++ {
        outlet[lo+t] = to_append[t]
    }

    return outlet
}
func str2int(inlet string) int {
    var outlet int = 0
    fmt.Sscanf(inlet, "%d", &outlet)
    return outlet
}

func str2int64(str string) int64 {
	var x int64
	fmt.Sscanf(str, "%d", &x)
	return x
}

func min(u, v int) int {
    if u < v {
        return u
    } else {
        return v
    }
}

func match(p, q string) bool {
    r := true
    l := min(len(p), len(q))

    for i := 0; i < l && r; i++ {
        if p[i] != q[i] {
            r = false
        }
    }

    return r
}

func smallest(array []int) int {
    s := array[0]
    r := 0

    for i, it := range array {
        if it < s {
            s = it
            r = i
        }
    }

    return r
}
