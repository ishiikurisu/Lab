cd src
go build csv2single.go
move csv2single.exe ..\c2s.exe
cd ..
c2s.exe data\teste.CSV
del c2s.exe
