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