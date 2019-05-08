# Lets specify compiler
CC = g++
CFLAGS = -c -std=c++11

# Source files.  We keep header files separate from the cpp files.
# Recall that we will compile cpp files, but we do not compile
# the header files.
HEADER = 
CPP = main.cpp
LIB = 

# Program name
PROGNAME = sort

# Object files
OBJ = $(CPP:.cpp=.o)

all: $(PROGNAME)

$(PROGNAME): $(OBJ) $(LIB)
	$(CC) -o $@ $(OBJ)

%.o: %.cpp $(HEADER)
	$(CC) $(CFLAGS) -D _VERBOSE_ -D _SEARCH_SN_ -D _SEARCH_NAMES_ -o $@ $<

run: $(PROGNAME)
	./$(PROGNAME)

# Target clean is phony, since it doesn't
# create a file called clean.  Notice that other
# targets --- all and message --- create file
# message.
.PHONY: clean

# We will use target clean to delete both the object files
# and the program.
clean:
	rm -rf $(PROGNAME) $(OBJ)
