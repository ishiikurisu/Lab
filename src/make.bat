SET SRC=%1

cls
g++ %SRC% -o emo.exe -lm -O2 -ansi -pipe -Wall
emo.exe ../data/thiago_emotiv.edf > log.txt
more log.txt
del emo.exe log.txt
