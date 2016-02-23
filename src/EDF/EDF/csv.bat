cd src
mingw32-make all
move *.exe ..
cd..
edf2csv data\teste.edf > data\teste.csv
REM del *.exe
