flags = -Wall -Wextra -Wl,-kill-at
nativeJava = -I"C:\Java\jdk\include" -I"C:\Java\jdk\include\win32"

summer: Summer.java
	javac Summer.java

calculator: Calculator.java summer
	javac Calculator.java

generateHeader: summer
	javah Summer

jni: generateHeader summer.c
	gcc -shared -m32 summer.c -o Summer.dll $(nativeJava) $(flags)

do: jni calculator
	java Calculator 2 32