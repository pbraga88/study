#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* Retorna uma string de caracteres, repesentando data e hora atuais. */

char* get_timestamp()
{
	time_t now = time(NULL);
	return asctime(localtime(&now));
}

int main(int argc, char* argv[])
{
	/* O arquivo no qual será salvo o timestamp. */
	char* filename = argv[1];

	/* Pega o timestamp. */
	char* timestamp = get_timestamp();

	/* Abre o arquivo para escrita. Caso o arquivo já exista, adiciona à ele. Caso contrário, 
	cria um novo arquivo. */
	int fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0777);

	/* Calcula o tamanho da string do timestamp. */
	size_t length = strlen(timestamp);

	/* Escreve o timestamp no arquivo. */
	write(fd, timestamp, length);

	/* Fecha o arquivo. */
	close(fd);
	
	return 0;
}