#ifdef EDFP_H

typedef struct
{
    DICT* header;
    short* record;
    size_t number_samples;
}
DATA_RECORD;
typedef DATA_RECORD DATAREC;

DATAREC* new_data_record()
{
    DATAREC* data_record = (DATAREC*) malloc(sizeof(DATAREC));

    data_record->header = map_new(8, dumb);
    data_record->record = (short*) malloc(sizeof(short));
    data_record->record[0] = 0;
    data_record->number_samples = 0;

    return data_record;
}

short read_short(FILE* stream)
{
    short i = 0;
    fread(&i, sizeof(short), 1, stream);
    return i;
}
short* push_back(short* array, short to_add)
{
    array = realloc(array, sizeof(short) * (array[0] + 2));
    array[++array[0]] = to_add;

    return array;
}
DATAREC* datarec_read(DATAREC* data_record, FILE* inlet, double duration)
{
    short sig;
    size_t i = 0;

    for (i = 0; i < duration * data_record->number_samples; ++i)
    {
        sig = read_short(inlet);
        data_record->record = push_back(data_record->record, sig);
    }

    return data_record;
}

#endif
