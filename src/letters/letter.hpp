#ifndef LETTER_H
#define LETTER_H 0
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

class Letter {
private:
	bool* process_line(const char*);
	char id;
	bool **pattern;
public:
	Letter(void);
	void load(char, const char*);
	int compare(Letter);
	bool get_pattern(int, int);
	char get_id();
};

Letter::Letter() {
	return;
}

bool* Letter::process_line(const char* line)
{
	bool *result = (bool*) malloc(8 * sizeof(bool));

	for (int i = 0; i < 8; ++i)
		result[i] = (line[i] == '*');

	return result;
}

void Letter::load(char identifier, const char *path)
{
	std::fstream inlet;
	std::string line;

	pattern = (bool**) malloc(8 * sizeof(bool*));
	inlet.open(path, std::fstream::in);

	for (int i = 0; i < 8; ++i)
	{
		std::getline(inlet, line);
		pattern[i] = process_line(line.c_str());
	}

	id = identifier;
	inlet.close();
}

int Letter::compare(Letter to_compare)
{
	int score = 0;

	for (int x = 0; x < 8; x++)
	{
		for (int y = 0; y < 8; y++)
		{
			if (pattern[x][y] == to_compare.get_pattern(x, y)) {
				score++;
			}
		}
	}

	return score;
}

bool Letter::get_pattern(int x, int y)
{
	return pattern[x][y];
}

char Letter::get_id()
{
	return id;
}

#endif
