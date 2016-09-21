edffile = data\edf\linhadebase.edf
csv  = data\edf\linhadebase.csv
ascii = data\edf\linhadebase.ascii

# EDF Headers
edf:
	go build github.com/ishiikurisu/edf

edf2ascii: edf
	go build github.com/lab-neuro-comp/EDF/edf2ascii

edfp2notes: edf
	go build github.com/lab-neuro-comp/EDF/edfp2notes

edf2csv: edf
	go build github.com/lab-neuro-comp/EDF/edf2csv

csv2single: edf
	go build github.com/lab-neuro-comp/EDF/csv2single

# SST Headers
sst:
	go build github.com/ishiikurisu/sst

# EDF programs
test: edfp2notes
	edfp2notes $(edffile)

e2a: edf2ascii
	edf2ascii $(edffile) > $(ascii)

e2c: edf2csv
	edf2csv $(edffile) > $(csv)

c2s: csv2single e2c
	csv2single $(csv)

# SST programs
sst-analyzer: sst
	go build github.com/lab-neuro-comp/SST/main

sst-simulation: sst-analyzer
	main data\sst
