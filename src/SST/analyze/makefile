options = -ansi -lm -O3 -Wall

single.exe: single.cpp analyze.hpp ssrt-calculator.hpp
	g++ single.cpp -o single.exe $(options)
analyze.exe: analyze.hpp ssrt-calculator.hpp analyze.cpp
	g++ analyze.cpp -o analyze.exe $(options)