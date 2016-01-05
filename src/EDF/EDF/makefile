options = -lm -O2 -pipe -ansi -Wall
headers = edf_spec.hpp edf.hpp record.hpp auxiliar.hpp
exec = emo.exe edf2yaml.exe edf2csv.exe

emo.exe: emotivedf.cpp $(headers)
	g++ emotivedf.cpp -o emo.exe $(options)

edf2yaml.exe: edf2yaml.cpp $(headers)
	g++ edf2yaml.cpp -o edf2yaml.exe $(options)

edf2csv.exe: edf2csv.cpp $(headers)
	g++ edf2csv.cpp -o edf2csv.exe $(options)

edfp: edfp.hpp edfp.cpp
	g++ edfp.cpp -o edfp.exe $(options)

edfp2csv.exe: edfp.hpp
	g++ edfp2csv.cpp -o edfp2csv.exe $(options)

all: $(exec)
