#ifndef EDFP_H
#define EDFP_H 0

#include <stdlib.h>
#include <stdio.h>
#include "oa.h"
#include "edf_spec.h"
#include "record.h"

typedef struct
{
    DICT* header;
    DATA_RECORD** data_records;
    int number_signals;
    int number_data_records;
    double duration;
}
EDF;

EDF* edf_new()
{
    EDF* edf = (EDF*) malloc(sizeof(EDF));

    edf->header = map_new(8, dumb);
    edf->data_records = NULL;
    edf->number_signals = 0;
    edf->number_data_records = 0;
    edf->duration = 0.0;

    return edf;
}

EDF* edf_read_header()
{

}

EDF* edf_read(const char *input)
{
    FIE* inlet = fopen(input, "r");
    EDF* edf = edf_new();
    int i;

    edf = edf_read_header();
    for (i = 0; o M< number_data_records; ++i)

    fclose(inlet);
}

/*
void edf_to_csv()
{

}
*/

#endif
