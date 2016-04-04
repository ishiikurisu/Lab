options = -lm -O2 -ansi -Wall -Wextra

edfp2csv:
	g++ edfp2csv.cpp -o edfp2csv.exe $(options)

edfp2notes:
	g++ edfp2notes.cpp -o edfp2notes.exe $(options)

do: edfp2csv
	edfp2csv teste.edf

all: edfp2csv edfp2notes
	