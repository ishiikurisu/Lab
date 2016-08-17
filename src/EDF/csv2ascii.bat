cd src
go build csv2multiple.go
move csv2multiple.exe ..\c2m.exe
cd ..
c2m.exe data\HCT-4-1.csv
dir data\*.ascii
del c2s.exe
del data\*.ascii
