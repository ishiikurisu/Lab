all: Main
	java Main
Main: Main.java Single
	javac Main.java
Single: Single.java Analyzer
	javac Single.java
Analyzer: SSRTCalculator Analyzer.java
	javac Analyzer.java
SSRTCalculator: SSRTCalculator.java
	javac SSRTCalculator.java