package edinburgh

type Hand struct {
    Preference string
}

func GetOptions() []string {
    options := make([]string, 10)

    options[0] = "Writing"
    options[1] = "Drawing"
    options[2] = "Throwing"
    options[3] = "Using scissors"
    options[4] = "Using a toothbrush"
    options[5] = "Using a knife (without a fork)"
    options[6] = "Using a spoon"
    options[7] = "Using a boom (upper hand)"
    options[8] = "Striking a match"
    options[9] = "Opening a box"

    return options
}

func Score(score int) string {
    result := "ambi"

    if score < -1 {
        result = "left"
    } else if score > 1 {
        result = "right"
    }

    return result
}
