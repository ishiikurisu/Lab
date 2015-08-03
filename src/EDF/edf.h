#ifndef EDFP_H
#define EDFP_H 0

#include "oa.h"
#include "edf_spec.h"
#include "record.h"

typedef struct
{
    DICT *header;
    DATA_RECORD **data_records;
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

EDF* edf_read_header(EDF* edf, FILE* inlet)
{
    LIST *spec = EDF_SPEC;
    DATAREC *datarec;
    char* data;
    size_t aux_number, bytes;
    int i = 0;

    spec = spec->next;
    while (compare(spec->value, "numbersignals") != EQUALS)
    {
        sscanf(mget(EDF_SPECS, spec->value), "%d", &bytes);
        data = read_bytes(inlet, bytes);
        printf("%s: %s\n", spec->value, data);
        mput(edf->header, spec->value, data);
        if (compare(spec->value, "datarecords") == EQUALS) {
            sscanf(data, "%d", &edf->number_data_records);
        }
        else if (compare(spec->value, "duration") == EQUALS) {
            sscanf(data, "%lf", &edf->duration);
        }
        else if (compare(spec->value, "numbersignals") == EQUALS) {
            sscanf(data, "%d", &edf->number_signals);
        }

        inc(spec);
    }

    edf->data_records = (DATAREC**) malloc( \
       edf->number_signals *  sizeof(DATAREC*));
    for (i = 0; i < edf->number_signals; ++i)
        edf->data_records[i] = new_data_record();
    while (spec != NULL)
    {
        sscanf(mget(EDF_SPECS, spec->value), "%d", &bytes);
        for (i = 0; i < edf->number_signals; ++i)
        {
            datarec = edf->data_records[i];
            data = read_bytes(inlet, bytes);
            printf("%s: %s\n", spec->value, data);
            mput(datarec->header, spec->value, data);
            if (compare(spec->value, "samplesrecord") == EQUALS) {
                sscanf(data, "%d",&aux_number);
                datarec->number_samples = (size_t) aux_number;
            }
        }
        inc(spec);
    }

    return edf;
}

EDF* edf_read(char *input)
{
    FILE *inlet = fopen(input, "r");
    EDF *edf = edf_new();
    /* int i; */

    printf("%p!\n", inlet);
    EDF_SETUP();
    edf = edf_read_header(edf, inlet);
    /*
    for (i = 0; i < number_data_records; ++i)
        edf_read_data_record(edf, inlet);
    */

    fclose(inlet);
    return edf;
}

/*
void edf_to_csv()
{

}
*/

#endif
