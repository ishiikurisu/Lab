#ifndef EMOTIV_H
#define EMOTIV_H 0

#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <map>

typedef struct 
{
	std::map<string, string> header;
	std::vector<string> *records;
} EMOTIV;

#include "emotiv_readfile.h"
EMOTIV* emotiv_readfile(FILE* inlet)
{
	EMOTIV* emotiv = (EMOTIV*) malloc(sizeof(EMOTIV));

	emotiv->header = emotiv_readheader(inlet);
	/* translate header data */
	/* read records */

	return emotiv;
}

// #include "emotiv_writefile.h"
void emotiv_writefile(FILE* outlet)
{

}

#endif