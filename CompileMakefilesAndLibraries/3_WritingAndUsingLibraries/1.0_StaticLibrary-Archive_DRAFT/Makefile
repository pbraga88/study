PROJECT=linkedList

C_SOURCE=$(wildcard ./src/*.c)

OBJ=$(subst .c,.o, $(subst src,obj, $(C_SOURCE)))

INC=include
LIB=lib

# -c: Compila arquivo objeto; -W: Warning; Wall: Warning para tudo; 
CFLAGS=-c 	    \
       -W	    \
       -Wall    \
       -ansi	\
       -pedantic

CC=gcc 

# Used to create static library
AR=ar

# Objects to create static library
static_lib += obj/printAndFree.o
static_lib += obj/linkedListOperations.o
static_lib += obj/numberOperations.o

# Se o "make" for passado sem target, os targets são printados
default:
	@ echo "Targets: all buildStatic staticLib clean print-<VAR>"

# To print variables: make print-<VAR>
print-%  : ; @echo $* = $($*)

# Build static lib
staticLib: objFolder libFolder $(OBJ)
	@ echo 'Build static lib libLinkedList.a'
	$(AR) cr lib/libLinkedList.a $(static_lib)
	@ echo ' '

buildStatic: staticLib
	@ echo 'Building Binary with static lib'
	$(CC) -o $(PROJECT)$@ obj/main.o -L$(LIB) -lLinkedList
	@ echo ' '

#Compile and link
all: objFolder $(PROJECT)

$(PROJECT): $(OBJ)
	@ echo 'Link to build binary: $@'
	$(CC) -o $@ $^
	@ echo ' '
# $@ = TARGET; $^ = Todos os arquivos dependentes
# O caracter '@' é utilizado para suprimir a mensagem a ser printada

./obj/main.o: ./src/main.c
	@ echo 'Build main obj: $<'
	$(CC) $(CFLAGS) -I $(INC) $< -o $@
	@ echo ' '
# $@ = TARGET; $< = Primeiro arquivo dependente

./obj/%.o: ./src/%.c
	@ echo 'Build obj: $<'
	$(CC) $(CFLAGS) -I $(INC) $< -o $@
	@ echo ' '
# Flag NDEBUG exclusiva para este projeto

objFolder:
	@ mkdir -p obj

libFolder:
	@ mkdir -p lib

clean:
	@ rm -rf ./obj/*.o ./lib/*.a $(PROJECT)* *~
	@ rmdir obj
	@ rmdir lib

.PHONY: all clean