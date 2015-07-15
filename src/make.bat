cls
g++ emotivedf.cpp -o emo.exe -lm -O2 -ansi -pipe -Wall
emo.exe ../data/thiago_emotiv.edf > log.txt
more log.txt
g++ emotivedf.cpp -o emo.exe -lm -O2 -ansi -pipe -Wall
rem emo.exe ../data/thiago_emotiv.edf > log.txt
emo.exe ../data/1.01.1.1.1.edf > log.txt
del emo.exe
