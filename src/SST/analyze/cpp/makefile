options = -ansi -lm -O3 -pipe -Wall

single: single.cpp analyze.hpp ssrt-calculator.hpp
	g++ single.cpp -o single.exe $(options)
multiple: multiple.cpp analyze.hpp ssrt-calculator.hpp toolbox.hpp
	g++ multiple.cpp -o multiple.exe $(options)