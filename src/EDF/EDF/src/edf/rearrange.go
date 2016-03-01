package edf

func rearrange(inlet []int16) []int16 {
    last := inlet[0]
    limit := len(inlet)
    midlet := make([]int, limit)
    outlet := make([]int16, limit)
    upperbound := max(inlet)
    lowerbound := min(inlet)
    margin := (upperbound - lowerbound)/10
    factor := 0
    situation := 0
    flag := false

    for i := 0; i < limit; i++ {
        it := inlet[i]

        switch situation {
            case 1: { // overflow
                if last < (it - margin) {
                    situation = 0
                    factor = 0
                }
            }
            case -1: { // underflow
                if last > (it + margin) {
                    situation = 0
                    factor = 0
                }
            }
            default: { // otherwise
                if last > (it + margin) { // overflows
                    situation = 1
                    factor = 8162
                    flag = true
                } else if last < (it - margin) { // underflows
                    situation = -1
                    factor = -8162
                    flag = true
                }
            }
        }

        midlet[i] = int(it) + factor
        last = it
    }

    // reorganize signal
    if flag {
        for i := 0; i < limit; i++ {
            outlet[i] = int16(midlet[i]/2)
        }
    }

    return outlet
}