cls
g++ emotivedf.cpp -o emo.exe -lm -O2 -ansi -pipe -Wall
emo.exe ../data/thiago_emotiv.edf > log.log
rem emo.exe ../data/1.01.1.1.1.edf > log.log
more log.log
rem del emo.exe
