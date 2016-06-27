sstpack = sst/SSRTCalculator.go sst/SSTReader.go sst/util.go
iconpath = data/icon.ico

do: main.go $(sstpack)
	go build main.go

iconize: $(iconpath)
	rcedit main.exe --set-icon $(iconpath)

build: do iconize
all: do
