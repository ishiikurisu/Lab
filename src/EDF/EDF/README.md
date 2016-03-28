Go support for EDF
==================

This folder provides a Go implementation of the old EDF format. It reads EDF files into two structures:

+ A map from strings to strings, representing the main header in the EDF file.
+ A slice of slices of int16, each one representing one channel's recording.

They can be accessed using the `ReadFile(string)` function. There already are two programs to convert these files into the CSV and the ASCII format: the `edf2csv` and the `edf2ascii` scripts.

To compile them, use the `makefile` present in the `src` folder.

Usage
-----

``` sh
edf2csv input_file.edf > output_file.csv
```

To Do
-----

- [ ] Add support for EDF+. That is, read the annotations channels into a separate slice and write them as a ASCII file.
- [ ] Write documentation in Go style.