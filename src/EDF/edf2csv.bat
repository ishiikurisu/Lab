cd src
mingw32-make edf2csv
move *.exe ..\e2c.exe
cd ..
REM e2c.exe data\joe-teste-17.02.16.13.56.33.edf > data\joe.csv
e2c.exe data\HCT-4-1.edf > data\HCT-4-1.csv
e2c.exe data\HCT-4-23.edf > data\HCT-4-23.csv
del e2c.exe
