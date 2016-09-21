edffile = data\testelinhadebase.edf
csv  = data\testelinhadebase.csv
ascii = data\testelinhadebase.ascii

# Headers
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

# Final programs
test: edfp2notes
	edfp2notes $(edffile)

e2a: edf2ascii
	edf2ascii $(edffile) > $(ascii)

e2c: edf2csv
	edf2csv $(edffile) > $(csv)

c2s: csv2single e2c
	csv2single $(csv)
