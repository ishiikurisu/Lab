oapath = -I"../.."
options = -lm -O2 -ansi -pipe -Wall

edf2ascii.exe: edf2ascii.h edf2ascii.c edf2csv.exe csv2ascii.exe
	gcc edf2ascii.c -o edf2ascii.exe $(options) $(oapath)
edf2csv.exe: edf_specs.txt
