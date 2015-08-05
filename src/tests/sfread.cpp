#include <iostream>
#include <stdio.h>

int main()
{
	std::string line;
	char key[32];
	int value;
	
	while (std::getline(std::cin, line))
	{
		sscanf(line.c_str(), "%[^=]s", &key, &value);
		printf("%s: %d\n", key, value);
	}	

	return 0;
}