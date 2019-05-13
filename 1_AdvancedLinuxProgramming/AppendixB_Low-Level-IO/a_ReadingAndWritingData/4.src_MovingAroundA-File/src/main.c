#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int zero = 0;
	const int megabyte = 1024 * 1024;
	
	char* filename = argv[1];
	size_t length = (size_t) atoi (argv[2]) * megabyte;

	/* Abrindo um novo arquivo */
	int fd = open(filename, O_WRONLY | O_CREAT | O_EXCL, 0666);
	
	/* Pula para 1 byte antes de onde quero o arquivo acabe */
	lseek(fd, length - 1, SEEK_SET);
	/* Escreve um único byte '0' */
	write(fd, &zero, 1);
	/* Fecha o arquivo */
	close(fd);

	return 0;
}