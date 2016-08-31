sourcefiles = src/kun/Domo.java
classfiles = kun/Domo.class

classes:
	javac -cp src -target 1.4 -source 1.4 -nowarn $(sourcefiles)

test: classes
	java -cp src kun.Domo

jar: classes
	jar cvfm target/domo.jar manifest.txt  -C src $(classfiles)

do: jar
	java -jar target/domo.jar
