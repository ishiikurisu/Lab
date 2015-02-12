all: Main
	java Main
Main: Main.java Single Multiple
	javac Main.java
Multiple: Multiple.java
	javac Multiple.java
Single: Single.java Analyzer
	javac Single.java
Analyzer: SSRTCalculator Analyzer.java
	javac Analyzer.java
SSRTCalculator: SSRTCalculator.java
	javac SSRTCalculator.java

jar: Main
	jar cvfe SST-analyzer.jar Main *.class

clean:
	del *.class