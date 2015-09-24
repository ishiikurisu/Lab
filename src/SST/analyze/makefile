options = -ansi -lm -O3 -Wall

single.exe: single.cpp analyze.hpp ssrt-calculator.hpp
	g++ single.cpp -o single.exe $(options)
analyze.exe: analyze.cpp analyze.hpp ssrt-calculator.hpp toolbox.hpp
	g++ analyze.cpp -o analyze.exe $(options)