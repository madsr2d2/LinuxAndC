# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS	:= -Wall -Wextra -g

# define output directory
OUTPUT	:= output

# define source directory
SRC		:= src

# define include directory
INCLUDE	:= include

ifeq ($(OS),Windows_NT)
MAIN	:= main.exe
SOURCEDIRS	:= $(SRC)
INCLUDEDIRS	:= $(INCLUDE)
FIXPATH = $(subst /,\,$1)
RM			:= del /q /f
MD	:= mkdir
else
MAIN	:= hnp_a6
SOURCEDIRS	:= $(shell find $(SRC) -type d)
INCLUDEDIRS	:= $(shell find $(INCLUDE) -type d)
FIXPATH = $1
RM = rm -f
MD	:= mkdir -p
endif

# define any directories containing header files other than /usr/include
INCLUDES	:= $(patsubst %,-I%, $(INCLUDEDIRS:%/=%))

# define the C source files
SOURCES		:= $(wildcard $(patsubst %,%/*.c, $(SOURCEDIRS)))

# define the C object files 
OBJECTS		:= $(SOURCES:.c=.o)

OUTPUTMAIN	:= $(call FIXPATH,$(OUTPUT)/$(MAIN))

all: $(OUTPUT) $(MAIN)
	@echo Executing 'all' complete!

$(OUTPUT):
	$(MD) $(OUTPUT)

$(MAIN): $(OBJECTS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(OUTPUTMAIN) $(OBJECTS) $(LFLAGS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

.PHONY: clean
clean:
	$(RM) $(OUTPUTMAIN)
	$(RM) $(call FIXPATH,$(OBJECTS))
	@echo Cleanup complete!

run: all
	./$(OUTPUTMAIN)
	@echo Executing 'run: all' complete!