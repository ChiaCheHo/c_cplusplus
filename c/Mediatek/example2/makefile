CC=gcc
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=example.c
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=example

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@