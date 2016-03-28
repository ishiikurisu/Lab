options = -lm -O2 -ansi -Wall -Wextra

edfp2csv:
	g++ edfp2csv.cpp -o edfp2csv.exe $(options)

do: edfp2csv
	edfp2csv teste.edf

all: do
	