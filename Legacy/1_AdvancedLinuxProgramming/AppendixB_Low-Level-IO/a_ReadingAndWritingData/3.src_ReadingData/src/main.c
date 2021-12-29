#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	unsigned char buffer[16];
	size_t offset = 0;
	size_t bytes_read;
	int i;

	/* Abre o arquivo para leitura */
	int fd = open(argv[1], O_RDONLY);

	/* Lê o arquivo, uma parte por vez. Continua até o final do arquivo. */
	do{
		bytes_read = read(fd, buffer, sizeof(buffer));
		/* Printa o offset no arquivo, seguido pelos bytes, propriamente ditos */
		printf("0x%06x: ", offset);
		for (i=0; i < bytes_read; ++i)
			printf("%02x ", buffer[i]);
		printf("\n");
		/* Guarda a contagem da posição no arquivo */
		offset += bytes_read;
	}
	while(bytes_read == sizeof(buffer));

	/* All done */
	close(fd);

	return 0;
}