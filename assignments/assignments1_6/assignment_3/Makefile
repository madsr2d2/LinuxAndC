# Define the C compiler to use
CC := gcc

# Define compiler flags
CFLAGS := -Wall -Wextra -g

# Define output directory
OUTPUT := output

# Define source directory
SRC := src

# Define include directory
INCLUDE := include
 
# Define output file name
MAIN := main

# Find source dirs in current directory
SOURCEDIRS := $(shell find $(SRC) -type d)

# Find include dirs in current directory
INCLUDEDIRS := $(shell find $(INCLUDE) -type d)

# Define remove command
RM := rm -f

# Needed for the clean target
FIXPATH = $1

# Define make dir command
MD := mkdir -p

# Generate includes
INCLUDES := $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# Define the C source files
SOURCES := $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))

# Define the C object files 
OBJECTS := $(SOURCES:.c=.o)

# Define main output file 
OUTPUTMAIN := $(OUTPUT)/$(MAIN)

# Make all 
all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

# Make the output dir
$(OUTPUT):
	$(MD) $(OUTPUT)

# Make main from object files 
$(MAIN): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS)

# Rule for making object files.
%.o : %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Declare "clean" as phony target
.PHONY: clean

# Clean 
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!

# Run main
run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!
