rsrc.syso: ed.manifest
	rsrc -manifest ed.manifest -o rsrc.syso

edx: rsrc.syso main.go
	go build -ldflags="-H windowsgui"

ed: rsrc.syso main.go
	go build

debug: ed
all: edx
