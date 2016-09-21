edf:
	go build github.com/ishiikurisu/edf

edf2ascii: edf
	go build github.com/ishiikurisu/edf2ascii

edfp2notes: edf
	go build github.com/ishiikurisu/edfp2notes

edf2csv: edf
	go build github.com/ishiikurisu/edf2csv

csv2single: edf
	go build github.com/ishiikurisu/csv2single

test: edfp2notes
	edfp2notes data/linhadebase.edf

e2a: edf2ascii
	edf2ascii data/linhadebase.edf > data/linhadebase.ascii

e2c: edf2csv
	edf2csv data/linhadebase.edf > data/linhadebase.csv

c2s: csv2single
	csv2single data/linhadebase.csv
