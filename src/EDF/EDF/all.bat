REM build edf2csv
cd src
mingw32-make all
move *.exe ..
cd..

REM translate data
edf2csv data\joe-teste-17.02.16.13.56.33.edf > data\joe.csv
csv2ascii data\joe.csv