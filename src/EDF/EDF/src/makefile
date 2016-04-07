edfpack = edf/spec.go edf/edfReader.go edf/edfWrite.go

edf2csv: edf2csv.go $(edfpack)
	go build edf2csv.go

edf2ascii: edf2ascii.go $(edfpack)
	go build edf2ascii.go

edfp2notes: edfp2notes.go $(edfpack)
	go build edfp2notes.go

all: edf2ascii
