LIST* EDF_SPEC;
DICT* EDF_SPECS;

void EDF_SETUP()
{
    EDF_SPEC = read_whole_file("edf_spec.txt");
    EDF_SPECS = new_map(8, dumb);

    EDF_SPECS = map_feed(EDF_SPECS, "edf_specs.txt", '=');
}
