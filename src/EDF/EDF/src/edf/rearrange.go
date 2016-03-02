package edf

func rearrange(inlet []int16) []int16 {
    var last int16 = 0
    limit := len(inlet)
    outlet := make([]int16, limit)

    for i := 0; i < limit; i++ {
        it := inlet[i]
		outlet[i] = (it - last)*128
        last = it
    }

    return outlet
}