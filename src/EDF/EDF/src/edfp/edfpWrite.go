package edfp

import "fmt"

/**
 *
 */
func WriteCSV(header map[string]string, records [][]int16) {
	fmt.Printf("header: %#v\n\n", header)
	fmt.Printf("records: %#v\n", records)
}