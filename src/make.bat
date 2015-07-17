cls
gcc csv_to_ascii.c -o csv.exe -lm -O2 -ansi
csv.exe ../data/ana_data.CSV
del csv.exe