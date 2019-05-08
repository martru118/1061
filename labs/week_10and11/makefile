CC = g++
CFLAGS = -c
LDFLAGS =
SRCS = main.cpp \
		Stack.cpp \
		Buffer.cpp \
		StackInt.cpp
HDRS = Buffer.h \
		Stack.h \
		StackInt.h
EXE = stack
OBJS = $(SRCS:.cpp=.o)

all: $(EXE) $(SRCS) $(HDRS)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $^

%.o: %.cpp $(HDRS)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: clean
clean:
	rm -f *o $(EXE) 