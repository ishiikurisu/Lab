cd src
mingw32-make all
move *.exe ..\e2c.exe
cd ..
e2c.exe data\joe-teste-17.02.16.13.56.33.edf > data\joe.csv
del e2c.exe
