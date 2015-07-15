std::map<std::string, size_t> EDF_SPEC;
std::vector<std::string> EDF_SPECS;

void EDF_SETUP()
{
	EDF_SPECS.push_back("version");
	EDF_SPECS.push_back("patient");
	EDF_SPECS.push_back("recording");
	EDF_SPECS.push_back("startdate");
	EDF_SPECS.push_back("starttime");
	EDF_SPECS.push_back("bytes_headerrecord");
	EDF_SPECS.push_back("reserved");
	EDF_SPECS.push_back("datarecords");
	EDF_SPECS.push_back("duration");
	EDF_SPECS.push_back("numbersignals");
	EDF_SPECS.push_back("label");
	EDF_SPECS.push_back("transducer");
	EDF_SPECS.push_back("physicaldimension");
	EDF_SPECS.push_back("physicalminimum");
	EDF_SPECS.push_back("physicalmaximum");
	EDF_SPECS.push_back("digitalminimum");
	EDF_SPECS.push_back("digitalmaximum");
	EDF_SPECS.push_back("prefiltering");
	EDF_SPECS.push_back("samples");
	EDF_SPECS.push_back("chanreserved");

	EDF_SPEC["version"]           = 8;
	EDF_SPEC["patient"]           = 80;
	EDF_SPEC["recording"]         = 80;
	EDF_SPEC["startdate"]         = 8;
	EDF_SPEC["starttime"]         = 8;
	EDF_SPEC["reserved"]          = 44;
	EDF_SPEC["datarecords"]       = 8;
	EDF_SPEC["duration"]          = 8;
	EDF_SPEC["numbersignals"]     = 4;
	EDF_SPEC["label"]             = 16;
	EDF_SPEC["transducer"]        = 80;
	EDF_SPEC["physicaldimension"] = 8;
	EDF_SPEC["physicalminimum"]   = 8;
	EDF_SPEC["physicalmaximum"]   = 8;
	EDF_SPEC["digitalminimum"]    = 8;
	EDF_SPEC["digitalmaximum"]    = 8;
	EDF_SPEC["prefiltering"]      = 8;
	EDF_SPEC["samplesrecord"]     = 8;
	EDF_SPEC["chanreserved"]      = 32;
}