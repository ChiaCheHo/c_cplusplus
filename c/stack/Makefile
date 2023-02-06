# Which compiler to use
CC = gcc
# Which flags to use, -ggdb -Wall etc...
CFLAGS = -Wall
# Which libraries to use, -lm -lefence etc...
LDFLAGS =
# Which object files are part of the final program
OBJFILES = stack.o main.o
# What to name the final prog
TARGET = stacktest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~