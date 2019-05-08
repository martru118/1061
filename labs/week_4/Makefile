#specify compiler
CC = g++
CFLAGS = -c

#source files
HEADER = count.h
CPP = main.cpp count.cpp

#output files
PROGNAME = arr
OBJ = $(CPP:.cpp=.o)

#execute program
default: run

all: $(PROGNAME)

$(PROGNAME): $(OBJ)
	$(CC) -o $(PROGNAME) $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -o $@ $<

run: all
	./$(PROGNAME) 10

#delete output files
.PHONY: clear
clear:
	-rm $(PROGNAME) $(OBJ)