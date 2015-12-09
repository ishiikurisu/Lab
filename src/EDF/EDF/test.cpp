#include "auxiliar.hpp"

int main(int argc, char const *argv[])
{
	std::string split_me = "joe frank is stupid";
	std::vector<std::string> splitted = split(split_me, ' ');

	for (std::vector<std::string>::iterator it = splitted.begin(); it != splitted.end(); ++it)
	{
		std::cout << *it << "\n";
	}
	
	return 0;
}