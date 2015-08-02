#ifdef EDFP_H

typedef struct
{
    DICT* header;
    short** records;
    size_t number_samples;
    size_t number_records;
}
DATA_RECORD;
typedef DATA_RECORD DATAREC

DATAREC* new_data_record()
{
    DATAREC* data_record = (DATAREC*) malloc(sizeof(DATAREC));

    data_record->header = map_new(8, dumb);
    data_record->records = NULL;
    data_record->number_samples = 0;
    data_record->number_records = 0;

    return data_record;
}

#endif
