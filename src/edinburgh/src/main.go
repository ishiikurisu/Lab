package main

import (
    "fmt"
    // "github.com/lxn/walk"
    . "github.com/lxn/walk/declarative"
    "./edinburgh"
)

func getLeftScore(answers ...Property) int {
    score := 0

    for _, answer := range answers {
        fmt.Print(answer)
        text := "yep"

        if answer == true {
            text = "yep"
        } else {
            text = "nope"
        }

        fmt.Printf(": %s\n", text)
    }

    return score
}

func getRightScore(answers ...Property) int {
    return 0
}

func getScore(left int, right int) {
    fmt.Printf("%s\n", edinburgh.Score(right-left))
}

func main() {
    options := edinburgh.GetOptions()
    hand := &edinburgh.Hand{"left"}
    l := "Left"
    r := "Right"
    score := 0

    MainWindow{
        Title: "Edinburgh Inventory",
        MinSize: Size{400, 400},
        Layout:  VBox{},
        DataBinder: DataBinder{
            DataSource: hand,
            AutoSubmit: true,
            OnSubmitted: func() {
                fmt.Println(hand)
            },
        },
        Children: []Widget{
            Label{
                Text: "Edinburgh Handness Inventory",
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
                            /*
                            Label{Text: options[3]},
                            Label{Text: options[4]},
                            Label{Text: options[5]},
                            Label{Text: options[6]},
                            Label{Text: options[7]},
                            Label{Text: options[8]},
                            Label{Text: options[9]},
                            */
                        },
                    },

                    /* answers */
                    VSplitter{
                        Children: []Widget{
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o0L", OnClicked: func() {score -= 1;} },
                                    RadioButton{Name: "o0X"},
                                    RadioButton{Name: "o0R", Value: r},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o1L", Value: l},
                                    RadioButton{Name: "o1X"},
                                    RadioButton{Name: "o1R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o2L", Value: l},
                                    RadioButton{Name: "o2X"},
                                    RadioButton{Name: "o2R"},
                                },
                            },
                            /*
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o3L", Value: l},
                                    RadioButton{Name: "o3X"},
                                    RadioButton{Name: "o3R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o4L", Value: l},
                                    RadioButton{Name: "o4X"},
                                    RadioButton{Name: "o4R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o5L", Value: l},
                                    RadioButton{Name: "o5X"},
                                    RadioButton{Name: "o5R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o6L", Value: l},
                                    RadioButton{Name: "o6X"},
                                    RadioButton{Name: "o6R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o7L", Value: l},
                                    RadioButton{Name: "o7X"},
                                    RadioButton{Name: "o7R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o8L", Value: l},
                                    RadioButton{Name: "o8X"},
                                    RadioButton{Name: "o8R"},
                                },
                            },
                            HSplitter{
                                Children: []Widget{
                                    RadioButton{Name: "o9L", Value: l},
                                    RadioButton{Name: "o9X"},
                                    RadioButton{Name: "o9R"},
                                },
                            },
                            */
                        },
                    },
                },
            },
            PushButton{
                Text: "Score me!",
                OnClicked: func() {
                    fmt.Println(score)
                    getScore(getLeftScore(Bind("o0L.Value"),
                                          Bind("o1L.Checked"),
                                          Bind("o2L.Checked"),
                                          /*
                                          Bind("o3L.Checked"),
                                          Bind("o4L.Checked"),
                                          Bind("o5L.Checked"),
                                          Bind("o6L.Checked"),
                                          Bind("o7L.Checked"),
                                          Bind("o8L.Checked"),
                                          Bind("o9L.Checked")*/),
                             getRightScore(Bind("o0R.Checked"),
                                           Bind("o1R.Checked"),
                                           Bind("o2R.Checked"),/*
                                           Bind("o3R.Checked"),
                                           Bind("o4R.Checked"),
                                           Bind("o5R.Checked"),
                                           Bind("o6R.Checked"),
                                           Bind("o7R.Checked"),
                                           Bind("o8R.Checked"),
                                           Bind("o9R.Checked")*/))
                },
            },
        },
    }.Run()
}
