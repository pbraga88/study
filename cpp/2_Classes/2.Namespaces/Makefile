# Makefile draft

# Project Name
PROJ_NAME = namespace

# .c files
C_SOURCE = $(wildcard ./src/*.cpp)

# .h files
H_SOURCE = $(wildcard ./src/*.h)

# Object files
OBJ = $(subst .cpp,.o,$(subst src,obj,$(C_SOURCE)))

# Compiler and linker
CC = g++

#Flags for compiler
CC_FLAGS = -c		\
           -W		\
           -Wall	\
           -ansi	\
           -pedantic

# Command used for clean
RM = rm -rf

#
# Compilation and Linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC compiler: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./obj/%.o: ./src/%.cpp ./src/%.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./obj/main.o: ./src/main.cpp $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p obj

clean:
	@ $(RM) ./obj/*.o $(PROJ_NAME) *~
	@ rmdir obj

.PHONY: all clean
