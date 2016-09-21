package sst

import "fmt"

func TestTime() {
    fmt.Printf("---\n")
    timestamp := "2015-09-18T15:22:21Z"
    fmt.Printf("Initial state: %s\n", timestamp)
    y, m, d := getDate(timestamp)
    fmt.Printf("Testing date: %#v %#v %#v\n", y, m, d)
    hr, mn, sc := getHour(timestamp)
    fmt.Printf("Testing hour: %#v %#v %#v\n", hr, mn, sc)
    fmt.Printf("Final test to unixtime: %#v\n", ConvertToUnixTime(timestamp))

    fmt.Printf("---\n")
    unixtime := ConvertToUnixTime(timestamp)
    fmt.Printf("Final test to timestamp: %s\n", ConvertToTimeStamp(unixtime))
}
