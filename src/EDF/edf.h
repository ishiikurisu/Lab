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

/*
EDF* edf_new()
{

}

EDF* read_edf_file()
{

}

void edf_to_csv()
{

}
*/

#endif
