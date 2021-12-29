PROJECT=inversoDoNum

C_SOURCE=$(wildcard ./src/*.c)

OBJ=$(subst .c,.o, $(subst src,obj, $(C_SOURCE)))

INC=include

# -c: Compila arquivo objeto; -W: Warning; Wall: Warning para tudo;
CFLAGS=-c 	    \
       -W	    \
       -Wall    \
       -ansi	\
       -pedantic

CC=gcc

# To print variables: make print-<VAR>
print-%  : ; @echo $* = $($*)

#Compile and link

all: objFolder $(PROJECT)

$(PROJECT): $(OBJ)
	@ echo 'Link to build binary: $@'
	$(CC) -o $@ $^
	@ echo ' '
# $@ = TARGET; $^ = Todos os arquivos dependentes
# O caracter '@' é utilizado para suprimir a mensagem a ser printada

./obj/main.o: ./src/main.c
	@echo 'Build main obj: $<'
	$(CC) $(CFLAGS) -I $(INC) $< -o $@
	@echo ' '
# $@ = TARGET; $< = Primeiro arquivo dependente

./obj/%.o: ./src/%.c
	@ echo 'Build obj: $<'
	$(CC) $(CFLAGS) -DNDEBUG=1 -I $(INC) $< -o $@
	@ echo ' '
# Flag NDEBUG exclusiva para este projeto

objFolder:
	@ mkdir -p obj

clean:
	@ rm -rf ./obj/*.o $(PROJECT) *~
	@ rmdir obj

.PHONY: all clean
