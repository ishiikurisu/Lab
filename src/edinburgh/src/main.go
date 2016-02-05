package main

import (
    "fmt"
    . "github.com/lxn/walk/declarative"
    "./edinburgh"
)

func answerAll(answered []bool) bool {
    result := true

    for _, answer := range answered {
        result = result && answer
    }

    return result
}

func GetScore(answers []int) string {
    score := 0

    for _, answer := range answers {
        score += answer
    }

    return edinburgh.Score(score)
}

func main() {
    options := edinburgh.GetOptions()
    // constants := edinburgh.GetConstants()
    answers := make([]int, 10)
    answered := make([]bool, 10)

    MainWindow{
        Title: "Edinburgh Inventory",
        MinSize: Size{600, 400},
        Layout:  VBox{},
        Children: []Widget{
            Label{
                Text: "Edinburgh Handedness Inventory",
            },
            HSplitter{
                Children:
                    []Widget{
                    /* options */
                    VSplitter{
                        StretchFactor: 1,
                        Children: []Widget{
                            Label{Text: options[0]},
                            Label{Text: options[1]},
                            Label{Text: options[2]},
                            Label{Text: options[3]},
                            Label{Text: options[4]},
                            Label{Text: options[5]},
                            Label{Text: options[6]},
                            Label{Text: options[7]},
                            Label{Text: options[8]},
                            Label{Text: options[9]},
                        },
                    },

                    /* answers */
                    VSplitter{
                        StretchFactor: 2,
                        Children: []Widget{
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[0] = -2; answered[0] = true;}, Text: "Always left" },
                                    RadioButton{OnClicked: func() {answers[0] = -1; answered[0] = true;}, Text: "Mostly left" },
                                    RadioButton{OnClicked: func() {answers[0] = 0; answered[0] = true;}, Text: "No pref" },
                                    RadioButton{OnClicked: func() {answers[0] = 1; answered[0] = true;}, Text: "Mostly right" },
                                    RadioButton{OnClicked: func() {answers[0] = 2; answered[0] = true;}, Text: "Always right" },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[1] = -2; answered[1] = true;} },
                                    RadioButton{OnClicked: func() {answers[1] = -1; answered[1] = true;} },
                                    RadioButton{OnClicked: func() {answers[1] = 0; answered[1] = true;} },
                                    RadioButton{OnClicked: func() {answers[1] = 1; answered[1] = true;} },
                                    RadioButton{OnClicked: func() {answers[1] = 2; answered[1] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[2] = -2; answered[2] = true;} },
                                    RadioButton{OnClicked: func() {answers[2] = -1; answered[2] = true;} },
                                    RadioButton{OnClicked: func() {answers[2] = 0; answered[2] = true;} },
                                    RadioButton{OnClicked: func() {answers[2] = 1; answered[2] = true;} },
                                    RadioButton{OnClicked: func() {answers[2] = 2; answered[2] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[3] = -2; answered[3] = true;} },
                                    RadioButton{OnClicked: func() {answers[3] = -1; answered[3] = true;} },
                                    RadioButton{OnClicked: func() {answers[3] = 0; answered[3] = true;} },
                                    RadioButton{OnClicked: func() {answers[3] = 1; answered[3] = true;} },
                                    RadioButton{OnClicked: func() {answers[3] = 2; answered[3] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[4] = -2; answered[4] = true;} },
                                    RadioButton{OnClicked: func() {answers[4] = -1; answered[4] = true;} },
                                    RadioButton{OnClicked: func() {answers[4] = 0; answered[4] = true;} },
                                    RadioButton{OnClicked: func() {answers[4] = 1; answered[4] = true;} },
                                    RadioButton{OnClicked: func() {answers[4] = 2; answered[4] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[5] = -2; answered[5] = true;} },
                                    RadioButton{OnClicked: func() {answers[5] = -1; answered[5] = true;} },
                                    RadioButton{OnClicked: func() {answers[5] = 0; answered[5] = true;} },
                                    RadioButton{OnClicked: func() {answers[5] = 1; answered[5] = true;} },
                                    RadioButton{OnClicked: func() {answers[5] = 2; answered[5] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[6] = -2; answered[6] = true;} },
                                    RadioButton{OnClicked: func() {answers[6] = -1; answered[6] = true;} },
                                    RadioButton{OnClicked: func() {answers[6] = 0; answered[6] = true;} },
                                    RadioButton{OnClicked: func() {answers[6] = 1; answered[6] = true;} },
                                    RadioButton{OnClicked: func() {answers[6] = 2; answered[6] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[7] = -2; answered[7] = true;} },
                                    RadioButton{OnClicked: func() {answers[7] = -1; answered[7] = true;} },
                                    RadioButton{OnClicked: func() {answers[7] = 0; answered[7] = true;} },
                                    RadioButton{OnClicked: func() {answers[7] = 1; answered[7] = true;} },
                                    RadioButton{OnClicked: func() {answers[7] = 2; answered[7] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[8] = -2; answered[8] = true;} },
                                    RadioButton{OnClicked: func() {answers[8] = -1; answered[8] = true;} },
                                    RadioButton{OnClicked: func() {answers[8] = 0; answered[8] = true;} },
                                    RadioButton{OnClicked: func() {answers[8] = 1; answered[8] = true;} },
                                    RadioButton{OnClicked: func() {answers[8] = 2; answered[8] = true;} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[9] = -2; answered[9] = true;} },
                                    RadioButton{OnClicked: func() {answers[9] = -1; answered[9] = true;} },
                                    RadioButton{OnClicked: func() {answers[9] = 0; answered[9] = true;} },
                                    RadioButton{OnClicked: func() {answers[9] = 1; answered[9] = true;} },
                                    RadioButton{OnClicked: func() {answers[9] = 2; answered[9] = true;} },
                                },
                            },
                        },
                    },
                },
            },
            PushButton{
                Text: "Score me!",
                OnClicked: func() {
                    if (answerAll(answered)) {
                        DisplayResult(GetScore(answers))
                        fmt.Printf("%s\n", GetScore(answers))
                    } else {
                        DisplayResult("nope")
                    }
                },
            },
        },
    }.Run()
}

func DisplayResult(result string) {
    comment := "You are ambidextrous"

    switch result {
    case "left":
        comment = "You are left handed"
        break
    case "right":
        comment = "You are right handed"
        break
    case "nope":
        comment = "Answer all questions!"
        break
    }

    MainWindow{
        Title: "Inventory Result",
        MinSize: Size{200, 100},
        Layout:  VBox{},
        Children: []Widget{
            Label{
                Text: comment,
            },
        },
    }.Run()
}
