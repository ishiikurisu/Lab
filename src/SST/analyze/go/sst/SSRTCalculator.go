package sst

func GetNeededVariables() []string {
	return []string{
		"PressStimulus.RT",
		"PressStimulus.ACC",
		"SoundStimulus.RT",
		"SoundStimulus.ACC",
		"VisualStimulus.Duration",
		"Procedure[Trial]",
	}
}

/**
 * Performs a study process on one SST data set
 * @param data a map relating the needed fields to arrays of the collected data
 * @return a map relating the desided measures with their respective calculations
 */
func AnalyzeSingle(data map[string][]string) map[string]float64 {
	result := make(map[string]float64)
	limit := len(data["Procedure[Trial]"])

	for i := 0; i < limit; i++ {
		switch data["Procedure[Trial]"][i] {
		case "PressProc":
			result = StudyPressProc(i, data, result)
		case "NotPressProc":
			result = StudyNotPressProc(i, data, result)
		}
	}

	return result
}

func StudyPressProc(where int,
	                data map[string][]string,
					stuff map[string]float64) map[string]float64 {
	return stuff
}

func StudyNotPressProc(where int,
	                   data map[string][]string,
					   stuff map[string]float64) map[string]float64 {
	return stuff
}
