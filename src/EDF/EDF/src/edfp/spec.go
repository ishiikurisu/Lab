package edfp

func GetSpecs() map[string]int {
    spec := make(map[string]int)

    spec["version"] = 8
    spec["patient"] = 80
    spec["recording"] = 80
    spec["startdate"] = 8
    spec["starttime"] = 8
    spec["bytesheader"] = 8
    spec["reserved"] = 44
    spec["datarecords"] = 8
    spec["duration"] = 8
    spec["numbersignals"] = 4
    spec["label"] = 16
    spec["transducer"] = 80
    spec["physicaldimension"] = 8
    spec["physicalminimum"] = 8
    spec["physicalmaximum"] = 8
    spec["digitalminimum"] = 8
    spec["digitalmaximum"] = 8
    spec["prefiltering"] = 80
    spec["samplesrecord"] = 8
    spec["chanreserved"] = 32

    return spec
}
