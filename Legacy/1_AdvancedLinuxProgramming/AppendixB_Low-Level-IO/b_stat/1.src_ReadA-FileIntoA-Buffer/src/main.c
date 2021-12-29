#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char* read_file(const char* filename, size_t* length);
char* buffer;

int main(int argc, char* argv[])
{
	/* TO IMPLEMENT */
	size_t tam = 0;
	printf("%s", read_file(argv[1], &tam));
	
	free(buffer);

	return 0;
}

/* Read the contents of FILENAME into a newly allocated buffer. The
size of the buffer is stored in *LENGTH. Returns the buffer, which
the caller must free. If FILENAME doesn't correspond to a regular
file, returns NULL. */
char* read_file(const char* filename, size_t* length)
{
	int fd; 
	struct stat file_info;

	/* Abre o arquivo */
	fd = open(filename, O_RDONLY);

	/* Busca as informações do arquivo */
	fstat(fd, &file_info);
	*length = file_info.st_size;

	/* Confirma que é um arquivo regular (de texto, neste caso) */
	if(!S_ISREG(file_info.st_mode))
	{
		/* Não é regular. Fecha o arquivo */
		close(fd);
		return NULL;
	}

	/* Aloca um buffer grande o suficiente para guardar o conteúdo do arquivo */
	buffer = (char*) malloc(*length);

	/* Lê o arquivo para o buffer */
	read(fd, buffer, *length);

	/* Fecha o arquivo e retorna o buffer */
	close(fd);
	return buffer;
}