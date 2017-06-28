edffile = data/edf/linhadebase.edf
edfedffile = data/edf/linhadebase.edf.edf
csv = data/edf/linhadebase.csv
ascii = data/edf/linhadebase.ascii
hct = data/edf/HCT/HCT-4-23.edf
hctcsv = data/edf/HCT/HCT-4-23.csv
dudu = data/edf/dudu.edf
duduascii = data/edf/dudu.ascii
sstexe = sst.exe
edffolder = data/edf

# EDF Headers
edf:
	go build github.com/ishiikurisu/edf

# EDF Programs
edf2ascii: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/edf2ascii

edfp2notes: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/edfp2notes

edf2csv: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/edf2csv

csv2single: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/csv2single

csv2multiple: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/csv2multiple

notes2csv: edf sst
	go build github.com/lab-neuro-comp/EDF-Tools/app/notes2csv

sample4github: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/sample

edf2edf: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/edf2edf

edf2csvnow: edf
	go build github.com/lab-neuro-comp/EDF-Tools/app/edf2csvnow

# EDF Test-driven development
test:
	go test github.com/ishiikurisu/edf/tests/csv2anything

# EDF Test cases
e2n: edfp2notes
	./edfp2notes $(edffile)

e2a: edf2ascii
	./edf2ascii $(edffile) > $(ascii)
	./edf2ascii $(dudu) > $(duduascii)

e2c: edf2csv
	./edf2csv $(edffile) > $(csv)
	./edf2csv $(hct) > $(hctcsv)

c2s: csv2single e2c
	./csv2single $(csv)

c2m: edf2csv csv2multiple
	./edf2csv $(dudu) > $(dudu).csv
	./csv2multiple $(dudu).csv
	./edf2csv $(hct) > $(hctcsv)
	./csv2multiple $(hctcsv)

n2c: notes2csv
	./notes2csv $(edffile)

sample: sample4github
	./sample $(edffolder)

e2e: edf2edf edf2ascii
	./edf2edf $(edffile) $(edffile).edf
	edf2ascii $(edffile).edf > $(edffile).edf.ascii

e2cn: edf2csvnow
	./edf2csvnow $(edffile) $(csv)

###############################################################################
# SST Headers
###############################################################################
sst:
	go build github.com/lab-neuro-comp/SST/src/sst

# SST Programs
sst-analyzer: sst
	go build -o $(sstexe) github.com/lab-neuro-comp/SST/src/main

# SST Test cases
sst-simulation: sst-analyzer
	$(sstexe) data/sst

# Build SST
sst-build: sst-simulation
	rcedit $(sstexe) --set-icon data/sst/icon.ico
