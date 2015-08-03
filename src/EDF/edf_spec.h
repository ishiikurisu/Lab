LIST* EDF_SPEC;
DICT* EDF_SPECS;

void EDF_SETUP()
{
    EDF_SPEC = read_whole_file("edf_spec.txt");
    EDF_SPECS = map_feed(new_map(8, dumb), "edf_specs.txt", '=');
}
