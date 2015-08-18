oapath = -I"C:\Users\cris\Documents\work\EEG\src"
options = -lm -O2 -ansi -pipe -Wall

some2ascii.exe: csv_to_ascii.c csv_to_ascii.h
	gcc csv_to_ascii.c -o some2ascii.exe $(options) $(oapath)
csv2ascii.exe: csv2ascii.c csv_to_ascii.h
	gcc csv2ascii.c -o csv2ascii.exe $(options) $(oapath)
