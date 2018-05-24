################################################################################
## Program name: CS 162 FinalProject
## Author: Khoa Nguyen
## Date: 03–18-2017
## Description: This is the makefile that contains rules specifying how the 
## executable of Final Project program is created, what files clean will delete, 
## and what files in the directory will zip include.
##
## CREDIT: the structure of this makefile is from the example of the makefile 
## tutorial in CS 162 W2017.
################################################################################

#
# Project Name
#
PROJ = Final_Project_Nguyen_Khoa

#
# Source Files
#
SRC  = main.cpp
SRC += Utilities.cpp
SRC += Engine.cpp
SRC += Space.cpp
SRC += City.cpp
SRC += Building.cpp
SRC += Room.cpp
SRC += Square.cpp
SRC += Floor.cpp
SRC += Wall.cpp
SRC += Fence.cpp
SRC += Tree.cpp
SRC += DarkMatter.cpp
SRC += Portal.cpp
SRC += Item.cpp
SRC += Character.cpp
SRC += DrStrange.cpp

#
# Create an object for each source file
#
OBJ = $(SRC:.cpp=.o)

#
# Output binary
#
BIN = $(PROJ).bin

#
# Compiler Flags
#
CFLAGS = -Wall -pedantic -std=gnu++11

#
# Valgrind Options
#
VOPT = --tool=memcheck --leak-check=full --show-leak-kinds=all --track-origins=yes

#
# Names of tags that aren't actually files. Without this, if there were ever a
# file in the directory with these names they would never run.
#
# Why? Because Make is checking to see if these files exist. If they already do
# it skips them!
#
.PHONY: default debug clean zip

#
# Default Behavior:
#     1. Remove everything to start from scratch
#     2. Compile the binary
#     3. Run it through valgrind for quicker debugging
#
default: clean $(BIN) debug

#
# Play game:
#
game: clean $(BIN)
        ./$(BIN)

#
# Notice the dependency chain.
#
# Order assuming no files exist:
#     1. Each .o file
#     2. Binary
#     3. Valgrind
# 
# Special Symbols:
#     @     Suppresses the command from being printed to the terminal)
#     $@    Name of tag
#     $^    Name of dependency
debug: $(BIN)
	@valgrind $(VOPT) ./$(BIN)

$(BIN): $(OBJ)
	@echo "CC	$@"
	@$(CXX) $(CFLAGS) $^ -o $@

#
# % is a wildcard. Anything that ends in ".o" will match this tag, and each
# tag depends on the same matching wildcard, but ending in ".cpp"
#
%.o: %.cpp
	@echo "CC	$^"
	@$(CXX) $(CFLAGS) -c $^

zip:
	zip $(PROJ).zip *.cpp *.hpp *.pdf makefile

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BIN)"
	@rm -f *.o $(BIN)
