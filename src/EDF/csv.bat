SET CSV=edf2csv.exe
SET INP=teste.edf
SET OUT=joe.csv
make %CSV%
%CSV% %INP% > %OUT%
del %CSV%
more %OUT%
