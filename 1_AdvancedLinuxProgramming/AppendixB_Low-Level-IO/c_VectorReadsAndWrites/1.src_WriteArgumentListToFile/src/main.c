#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	int fd;
	struct iovec* vec;
	struct iovec* vec_next;
	int i;
	/* Buffer com caracter de nova lina*/
	char newline = '\n';
	/* Skip past the first two elements of the argument list. Element
	0 is the name of this program, and element 1 is the output
	filename. */
	argc -= 2;
	argv += 2;

	/* Allocate an array of iovec elements. We'll need two for each
	element of the argument list, one for the text itself, and one for
	a newline. */
	vec = (struct iovec*) malloc(2 * argc * sizeof(struct iovec));

	/* Loop over the argument list, building the iovec entries. */
	vec_next = vec;
	for(i = 0; i < argc; ++i)
	{
		
	}


	return 0;
}