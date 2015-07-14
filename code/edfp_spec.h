std::map<std::string, size_t> EDFP_SPEC;
std::vector<std::string> EDFP_SPECS;

void EDFP_SETUP()
{
	EDFP_SPECS.push_back("version");
	EDFP_SPECS.push_back("patient");
	EDFP_SPECS.push_back("recording");
	EDFP_SPECS.push_back("startdate");
	EDFP_SPECS.push_back("starttime");
	EDFP_SPECS.push_back("bytes_headerrecord");
	EDFP_SPECS.push_back("reserved");
	EDFP_SPECS.push_back("datarecords");
	EDFP_SPECS.push_back("duration");
	EDFP_SPECS.push_back("numbersignals");
	EDFP_SPECS.push_back("label");
	EDFP_SPECS.push_back("transducer");
	EDFP_SPECS.push_back("physicaldimension");
	EDFP_SPECS.push_back("physicalminimum");
	EDFP_SPECS.push_back("physicalmaximum");
	EDFP_SPECS.push_back("digitalminimum");
	EDFP_SPECS.push_back("digitalmaximum");
	EDFP_SPECS.push_back("prefiltering");
	EDFP_SPECS.push_back("samplesrecord");
	EDFP_SPECS.push_back("chanreserved");

	EDFP_SPEC["version"]           = 8;
	EDFP_SPEC["patient"]           = 80;
	EDFP_SPEC["recording"]         = 80;
	EDFP_SPEC["startdate"]         = 8;
	EDFP_SPEC["starttime"]         = 8;
	EDFP_SPEC["reserved"]          = 44;
	EDFP_SPEC["datarecords"]       = 8;
	EDFP_SPEC["duration"]          = 8;
	EDFP_SPEC["numbersignals"]     = 4;
	EDFP_SPEC["label"]             = 16;
	EDFP_SPEC["transducer"]        = 80;
	EDFP_SPEC["physicaldimension"] = 8;
	EDFP_SPEC["physicalminimum"]   = 8;
	EDFP_SPEC["physicalmaximum"]   = 8;
	EDFP_SPEC["digitalminimum"]    = 8;
	EDFP_SPEC["digitalmaximum"]    = 8;
	EDFP_SPEC["prefiltering"]      = 8;
	EDFP_SPEC["samplesrecord"]     = 8;
	EDFP_SPEC["chanreserved"]      = 32;
}