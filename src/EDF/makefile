edf = github.com/ishiikurisu/edf

edf:
	go build $(edf)

edf2ascii: edf
	go build github.com/ishiikurisu/edf2ascii

edfp2notes: edf
	go build github.com/ishiikurisu/edfp2notes

csv2single: edf
	go build github.com/ishiikurisu/csv2single

test: edfp2notes
	edfp2notes data/linhadebase.edf

e2a: edf2ascii
	edf2ascii data/linhadebase.edf > data/linhadebase.ascii
