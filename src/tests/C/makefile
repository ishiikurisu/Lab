run: main
	main.exe

main: lib
	gcc main.c dd.a

lib:
	gcc lib/dd.c
	ar cr dd.a dd.o
