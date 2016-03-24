package sst

import "fmt"
import "os"

func GetAnalysisParameters() []string {
	return []string {
		"totalGo",
		"correctGo",
		"totalStop",
		"correctStop",
		"%INHIB",
		"%AUS",
		"SSD",
		"RT",
		"SSRT",
	}
}

/**
 * <p> Generates an analysis structure. Consists of a map relating a parameter
 *     to a number. The needed parameters can be obtained through the 
 *     "GetAnalysisParameters() string" function.
 * </p>
 * @return the analysis structure
 */
func BeginAnalysis() map[string]float64 {
	data := make(map[string]float64) 

	for _, param := range GetAnalysisParameters() {
		data[param] = 0
	}

	return data
}

/**
 * Updates a multiple analysis structure
 * @param inlet the structure to increment data
 * @param outlet the structure that will be incremented
 * @return outlet with the appropriate changes
 */
func UpdateAnalysis(inlet, outlet map[string]float64) map[string]float64 {
	return outlet
}

func EndAnalysis(inlet map[string]float64) map[string]float64 {
	return make(map[string]float64)
}

/**
 * Formats the output of an analysis structure
 * @param data the analysis structure
 * @return a string containing the formatted structure
 */
func FormatOutput(data map[string]float64) (box string) {
	for _, param := range GetAnalysisParameters() {
		box += fmt.Sprintf("%s: %v\n", param, data[param])
	}
	return 
}

/**
 * Writes data of an analysis structure to a stream
 * @param outlet pointer to the chosen file. if nil, writes to stdout
 * @param data the string to be written on the stream
 */
func WriteSingle(outlet *os.File, data string) {
	if outlet == nil {
		fmt.Printf("%s", data)
	} else {
		fmt.Fprintf(outlet, "%s", data)
	}
}