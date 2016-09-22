edffile = data\edf\linhadebase.edf
csv = data\edf\linhadebase.csv
ascii = data\edf\linhadebase.ascii

# EDF Headers
edf:
	go build github.com/ishiikurisu/edf

# EDF Programs
edf2ascii: edf
	go build github.com/lab-neuro-comp/EDF/app/edf2ascii

edfp2notes: edf
	go build github.com/lab-neuro-comp/EDF/app/edfp2notes

edf2csv: edf
	go build github.com/lab-neuro-comp/EDF/app/edf2csv

csv2single: edf
	go build github.com/lab-neuro-comp/EDF/app/csv2single

notes2csv: edf sst
	go build github.com/lab-neuro-comp/EDF/app/notes2csv

# EDF Test cases
e2n: edfp2notes
	edfp2notes $(edffile)

e2a: edf2ascii
	edf2ascii $(edffile) > $(ascii)

e2c: edf2csv
	edf2csv $(edffile) > $(csv)

c2s: csv2single e2c
	csv2single $(csv)

n2c: notes2csv
	notes2csv $(edffile)

###############################################################################
# SST Headers
sst:
	go build github.com/lab-neuro-comp/SST/src/sst

# SST Programs
sst-analyzer: sst
	go build github.com/lab-neuro-comp/SST/src/main

# SST Test cases
sst-simulation: sst-analyzer
	main data\sst
