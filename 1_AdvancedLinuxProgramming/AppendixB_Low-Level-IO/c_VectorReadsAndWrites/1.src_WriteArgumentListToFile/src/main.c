#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int fd;
	struct iovec* vec;
	struct iovec* vec_next;
	int i;
	/* Buffer com caracter de nova lina*/
	char newline = '\n';
	/* O primeiro elemento passado no command line é o nome do arquivo (filename) */
	char* filename = argv[1];
	/* Skip past the first two elements of the argument list. Element
	0 is the name of this program, and element 1 is the output
	filename. */
	argc -= 2;
	argv += 2;

	/* Allocate an array of iovec elements. We'll need two for each
	element of the argument list, one for the text itself, and one for
	a newline. */
	vec = (struct iovec*) malloc(2 * argc * sizeof(struct iovec));
	printf("DEBUG: vec points to: %p\n",(void *) vec);
	printf("DEBUG: Size of iovec struct: %zu\n", sizeof(struct iovec));
	/* Loop over the argument list, building the iovec entries. */
	vec_next = vec;
	for(i = 0; i < argc; ++i)
	{
		/* O primeiro elemento é o próprio texto do argumento passado. */
		vec_next->iov_base = argv[i];
		vec_next->iov_len = strlen(argv[i]);
		printf("DEBUG: %p\n",(void *) vec_next);
		++vec_next;
		/* O segundo elemento é um caracter de nova linha '\n'. Não tem problema
		multimplos elementos da matriz 'struct iovec' apontarem para a mesma região 
		de memória. */
		vec_next->iov_base = &newline;
		vec_next->iov_len = 1;
		printf("DEBUG: \t%p\n",(void *) vec_next);
		++vec_next;
	}
	/* Escrevendo os argumentos no arquivo. */
	fd = open(filename, O_WRONLY | O_CREAT);
	writev(fd, vec, 2 * argc);
	close(fd);
	free(vec);

	return 0;
}