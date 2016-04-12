Go support for EDF+
===================

This folder atempt to provide a Go implementation of the EDF format. It reads EDF files into two structures:

+ A map from strings to strings, representing the main header in the EDF file.
+ A slice of slices of int16, each one representing one channel's recording.

They can be accessed using the `ReadFile(string)` function. There already are two programs to convert these files into the CSV and the ASCII format: the `edf2csv` and the `edf2ascii` scripts. To convert from CSV to ASCII, use the `csv2single` and `csv2multiple` programs.

To compile them, use the `makefile` present in the `src` folder.
```

Current State
-------------

Right now, the old EDF format is implemented, but we want to add support for annotations so we are compatible with the new EDF+ format. The goal is to read the EDF file into two other files: an output file containing the signals (just like we are doing right now, divinding the file into a CSV or an ASCII one) and another text file storing the annotations as a list (probrably in YAML or CSV).

To Do
-----

- [ ] Add support for EDF+. That is, read the annotations channels into a separate slice and write them as a ASCII file.
- [ ] Write documentation in Go style.