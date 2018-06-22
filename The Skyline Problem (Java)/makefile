GS = -g
JC = javac
.SUFFIXES: .java .class
.java.class:
	        $(JC) $(JFLAGS) $*.java

CLASSES = \
	  main.java \
	  currentAdressAndFindPoint.java \
	  pairPoint.java \
	  printConsolePoint.java \
	  rectangles.java \
	  windowClass.java		

default: classes

classes: $(CLASSES:.java=.class)

clean:
	        $(RM) *.class

