# Which compiler to use
CC = g++
# Which flags to use, -ggdb -Wall etc...
CFLAGS = -Wall
# Which libraries to use, -lm -lefence etc...
LDFLAGS =
# Which object files are part of the final program
OBJFILES = vector.o
# What to name the final prog
TARGET = vector

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~