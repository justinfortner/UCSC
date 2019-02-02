#Justin Fortner
#ID#1481947
#jfortner
#CS101 PA3 Tantalo
#Makefile

#Makefile given on class website edited as allowed by the lab manual

#executable Sparse file
MAINCLASS  = Sparse
JAVAC      = javac 
JAVASRC    = $(wildcard *.java)
SOURCES    = $(JAVASRC) makefile README
CLASSES    = $(patsubst %.java, %.class, $(JAVASRC))
JARCLASSES = $(patsubst %.class, %*.class, $(CLASSES))
JARFILE    = $(MAINCLASS) 

all: $(JARFILE)
	
$(JARFILE): $(CLASSES)
	echo Main-class: $(MAINCLASS) > Manifest
	jar cvfm $(JARFILE) Manifest $(JARCLASSES)
	chmod +x $(JARFILE)
	rm Manifest

%.class: %.java
	$(JAVAC) $<

	
#clean .class and Sparse
clean:
	rm -f *.class $(JARFILE)