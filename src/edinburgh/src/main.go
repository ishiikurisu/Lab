package main

import (
    "fmt"
    . "github.com/lxn/walk/declarative"
    "./edinburgh"
)

func GetScore(answers []int) string {
    score := 0

    for _, answer := range answers {
        score += answer
    }

    return edinburgh.Score(score)
}

func main() {
    options := edinburgh.GetOptions()
    answers := make([]int, 10)

    MainWindow{
        Title: "Edinburgh Inventory",
        MinSize: Size{400, 400},
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
                        Children: []Widget{
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[0] = -1}, Text: "Left" },
                                    RadioButton{OnClicked: func() {answers[0] = 0}, Text: "No pref" },
                                    RadioButton{OnClicked: func() {answers[0] = 1}, Text: "Right" },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[1] = -1} },
                                    RadioButton{OnClicked: func() {answers[1] = 0} },
                                    RadioButton{OnClicked: func() {answers[1] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[2] = -1} },
                                    RadioButton{OnClicked: func() {answers[2] = 0} },
                                    RadioButton{OnClicked: func() {answers[2] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[3] = -1} },
                                    RadioButton{OnClicked: func() {answers[3] = 0} },
                                    RadioButton{OnClicked: func() {answers[3] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[4] = -1} },
                                    RadioButton{OnClicked: func() {answers[4] = 0} },
                                    RadioButton{OnClicked: func() {answers[4] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[5] = -1} },
                                    RadioButton{OnClicked: func() {answers[5] = 0} },
                                    RadioButton{OnClicked: func() {answers[5] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[6] = -1} },
                                    RadioButton{OnClicked: func() {answers[6] = 0} },
                                    RadioButton{OnClicked: func() {answers[6] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[7] = -1} },
                                    RadioButton{OnClicked: func() {answers[7] = 0} },
                                    RadioButton{OnClicked: func() {answers[7] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[8] = -1} },
                                    RadioButton{OnClicked: func() {answers[8] = 0} },
                                    RadioButton{OnClicked: func() {answers[8] = 1} },
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{OnClicked: func() {answers[9] = -1} },
                                    RadioButton{OnClicked: func() {answers[9] = 0} },
                                    RadioButton{OnClicked: func() {answers[9] = 1} },
                                },
                            },
                        },
                    },
                },
            },
            PushButton{
                Text: "Score me!",
                OnClicked: func() {
                    DisplayResult(GetScore(answers))
                    fmt.Printf("%s\n", GetScore(answers))
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
