cd src
go build csv2multiple.go
move csv2multiple.exe ..\c2m.exe
cd ..
c2m.exe data\HCT-4-1.csv
c2m.exe data\HCT-4-23.csv
dir data\*.ascii
del csv2multiple.exe
