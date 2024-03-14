# Target file name
TARGET ?= output_file

# List of source files
SOURCES = string.c

# Compiler and flags
CC = clang
CFLAGS = -Wall -O2

# Linker and flags
LD = clang
LDFLAGS =

# List of object files
OBJECTS = $(SOURCES:.c=.o)

# Extract the target file name from the source file names
TARGET = $(basename $(SOURCES))

# Default target
all: $(TARGET)

# Linker rule
$(TARGET): $(OBJECTS)
		$(LD) $(LDFLAGS) -o $@ $^

# Compiler rule
%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $<

# Clean target
clean:
		rm -f $(TARGET) $(OBJECTS)
