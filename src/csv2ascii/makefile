oapath = -I"C:\Users\cris\Documents\work\EEG\src"
options = -lm -O2 -ansi -pipe -Wall

csv2ascii.exe: csv_to_ascii.c csv_to_ascii.h
	gcc csv_to_ascii.c -o csv2ascii.exe $(options) $(oapath)
all2ascii.exe: all2ascii.c csv_to_ascii.h
	gcc all2ascii.c -o all2ascii.exe $(options) $(oapath)
