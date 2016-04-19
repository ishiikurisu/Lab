cls
cd src
go build edfp2notes.go
move edfp2notes.exe ..\c2n.exe
cd ..
c2n.exe data\testelinhadebase.edf
del c2n.exe
