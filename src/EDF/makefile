sourcefiles = src/br/unb/biologiaanimal/edf/EDF.java
classfiles = src/br/unb/biologiaanimal/edf/EDF.class
classname = br.unb.biologiaanimal.edf.EDF
targetname = target/edf.jar

classes:
	javac -target 1.4 -source 1.4 -nowarn $(sourcefiles)

test: classes
	java -cp src $(classname)

jar: classes
	jar cvfm $(targetname) manifest.txt  -C src $(classfiles)

do: jar
	java -jar $(targetname)
