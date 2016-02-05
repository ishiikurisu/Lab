options = -lm -O2 -pipe -ansi -Wall -Wextra -I"src" -ffast-math
headers = src/edf_spec.hpp src/edf.hpp src/record.hpp src/auxiliar.hpp
exec = emo.exe edf2yaml.exe edf2csv.exe

emo.exe: bin/emotivedf.cpp $(headers)
	g++ bin/emotivedf.cpp -o emo.exe $(options)

edf2yaml.exe: bin/edf2yaml.cpp $(headers)
	g++ bin/edf2yaml.cpp -o edf2yaml.exe $(options)

edf2csv.exe: bin/edf2csv.cpp $(headers)
	g++ bin/edf2csv.cpp -o edf2csv.exe $(options)

edfp: src/edfp.hpp bin/edfp.cpp
	g++ bin/edfp.cpp -o edfp.exe $(options)

edfp2csv.exe: src/edfp.hpp bin/edfp2csv.cpp
	g++ bin/edfp2csv.cpp -o edfp2csv.exe $(options)

all: $(exec)
