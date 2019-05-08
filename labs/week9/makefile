#specify compiler
CC = g++
CFLAGS = -c

#source files
CPP = sr.cpp
HEADER = 

#output files
PROGNAME = sr
OBJ = $(CPP:.cpp=.o)

#execute program
default: run

all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) -o $(PROGNAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -o $@ $<

run: all
	./$(PROGNAME) file.txt 2015
	./$(PROGNAME) file-big.txt also

#delete object files
.PHONY: clear
clear:
	-rm $(PROGNAME) $(OBJ)