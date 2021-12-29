PROJECT=linkedList

# C_SOURCE=$(wildcard ./src/*.c)
LIB_SOURCE=$(wildcard ./lib_src/*.c)

OBJ=$(subst .c,.o, $(subst lib_src,obj, $(LIB_SOURCE)))
S_OBJ=$(subst .c,.o, $(subst lib_src,s_obj, $(LIB_SOURCE)))

INC = include
LIB=lib

# -c: Compila arquivo objeto; -W: Warning; Wall: Warning para tudo; 
CFLAGS=-c 	    \
       -W	    \
       -Wall    \
       -ansi	\
       -pedantic 
	   
CFLAGS += -include $(INC)/numberOperations.h

CC=gcc

# Used to create static library
AR=ar

# Se o "make" for passado sem target, os targets são printados
default:
	@ echo "Targets: buildStatic buildShared staticLib sharedLib clean print-<VAR>"

# To print variables: make print-<VAR>
print-%  : ; @echo $* = $($*)

# Build Shared lib and objects
sharedLib: shared_objFolder libFolder sharedObj
	@ echo 'Build Shared lib libLinkedList.so'
	$(CC) -shared -fPIC -o ./lib/libLinkedList.so $(S_OBJ)
	@ echo ' '

sharedObj: $(S_OBJ)

./s_obj/%.o: ./lib_src/%.c
	@ echo 'Build shared object: $@'
	$(CC) $(CFLAGS) -c -fPIC -I $(INC)  $< -o $@
	@ echo ' '

buildShared: sharedLib
	@ echo 'Build Binary with shared lib'
	$(CC) $(CFLAGS) -o $(PROJECT)_shared src/main.c -I $(INC) -L$(LIB) -lLinkedList 
	@ echo ' '

# Build static lib and Binary
staticLib: objFolder libFolder $(OBJ)
	@ echo 'Build static lib libLinkedList.a'
	$(AR) cr lib/libLinkedList.a $(OBJ)
	@ echo ' '

buildStatic: staticLib
	@ echo 'Building Binary with static lib'
	$(CC) -o $(PROJECT)_static src/main.c -I $(INC) -L$(LIB) -lLinkedList
	@ echo ' '

./obj/%.o: ./lib_src/%.c
	@ echo 'Build obj: $<'
	$(CC) $(CFLAGS) -I $(INC) $< -o $@
	@ echo ' '

all: buildStatic buildShared

objFolder:
	@ mkdir -p obj

libFolder:
	@ mkdir -p lib

shared_objFolder:
	@ mkdir -p s_obj

clean:
	@ rm -rf ./obj/*.o ./lib/* $(PROJECT)* *~ obj s_obj

.PHONY: all clean $(shared_obj) $(shared_src)