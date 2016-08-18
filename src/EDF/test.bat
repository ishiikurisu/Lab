rem cls
rem cd src
rem gcc test.c -o test.exe
rem move test.exe ..
rem cd ..
rem test.exe data\HCT-4-1.csv
rem del test.exe

cls
cd src
go build test.go
move test.exe ..
cd ..
test.exe data\HCT-4-1.edf
test.exe data\testelinhadebase.edf
del test.exe