std::string read_header_line(FILE* inlet)
{
	std::string output;
	char just_read;

	while (scanf("%c", &just_read), just_read != '\n')
	{
		output += just_read;
	}

	return output;
}

std::map<string, string> emotiv_readheader(FILE* inlet)
{
	std::map<string, string> output;
	std::string header_line;

	header_line = read_header_line(inlet);
	output = 

	return output;
}