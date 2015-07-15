cls
g++ emotivedf.cpp -o emo.exe -lm -O2 -ansi -pipe -Wall
rem emo.exe ../data/thiago_emotiv.edf > log.log
emo.exe ../data/1.01.1.1.1.edf > log.log
more log.log
del emo.exe
