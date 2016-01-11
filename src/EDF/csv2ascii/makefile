oapath = -I"../.." -I"src"
options = -lm -O2 -ansi -pipe -Wall

some2ascii.exe: bin/some2ascii.c src/some2ascii.h
	gcc bin/some2ascii.c -o some2ascii.exe $(options) $(oapath)
csv2ascii.exe: bin/csv2ascii.c src/csv2ascii.h
	gcc bin/csv2ascii.c -o csv2ascii.exe $(options) $(oapath)
csv2fullascii.exe: bin/csv2fullascii.c src/csv2fullascii.h
	gcc bin/csv2fullascii.c -o csv2fullascii.exe $(options) $(oapath)

all: csv2ascii.exe
