edffile = data\edf\linhadebase.edf
csv = data\edf\linhadebase.csv
ascii = data\edf\linhadebase.ascii
hct = data\edf\HCT\HCT-4-23.edf
hctcsv = data\edf\HCT\HCT-4-23.csv
sstexe = sst.exe

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

csv2multiple: edf
	go build github.com/lab-neuro-comp/EDF/app/csv2multiple

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

c2m: edf2csv csv2multiple
	edf2csv $(hct) > $(hctcsv)
	csv2multiple $(hctcsv)

n2c: notes2csv
	notes2csv $(edffile)

###############################################################################
# SST Headers
sst:
	go build github.com/lab-neuro-comp/SST/src/sst

# SST Programs
sst-analyzer: sst
	go build -o $(sstexe) github.com/lab-neuro-comp/SST/src/main

# SST Test cases
sst-simulation: sst-analyzer
	$(sstexe) data\sst

# Build SST
sst-build: sst-simulation
	rcedit $(sstexe) --set-icon data\sst\icon.ico
