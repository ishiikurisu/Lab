package edinburgh

func GetOptions() []string {
    options := make([]string, 10)

    options[0] = "Writing"
    options[1] = "Drawing"
    options[2] = "Throwing"
    options[3] = "Using scissors"
    options[4] = "Using a toothbrush"
    options[5] = "Using a knife (without a fork)"
    options[6] = "Using a spoon"
    options[7] = "Using a broom (upper hand)"
    options[8] = "Striking a match"
    options[9] = "Opening a box"

    return options
}

func Score(score int) string {
    result := "ambi"

    if score < -2 {
        result = "left"
    } else if score > 2 {
        result = "right"
    }

    return result
}

func GetConstants() map[string]string {
    constants := make(map[string]string)

    constants["TITLE"] = "Edinburgh Handedness Inventory"

    return constants
}
