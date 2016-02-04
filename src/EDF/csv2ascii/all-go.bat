cd src
go build csv2single.go
move csv2single.exe ..\target\c2s.exe
cd ..
target\c2s.exe data\teste.CSV
