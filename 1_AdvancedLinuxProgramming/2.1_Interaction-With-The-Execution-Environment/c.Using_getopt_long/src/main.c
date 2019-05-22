#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>

/* Program Name */

const char* program_name;

/* Prints usage information for this program to STREAM (typically
stdout or stderr), and exit the program with EXIT_CODE. Does not
return. */

void print_usage(FILE* stream, int exit_code)
{
	fprintf(stream, "Usage: %s options [ inputfile .... ]\n", program_name);
	fprintf(stream,
			" -h --help Display this usage information.\n"
			" -o --output filename Write output to file.\n"
			" -v --verbose Print verbose messages.\n");
	exit(exit_code);
}

int main(int argc, char** argv)
{
	int next_option;

	/* Uma string listando as opções short válidas */
	/*const char* const short_options = "ho:v";*/
	const char* short_options = "ho:v";

	/* Uma matriz descrevendo as opções do tipo long válidas */
	const struct option long_options[] ={
		{ "help", 0, NULL, 'h' },
		{ "output", 1, NULL, 'o' },
		{ "verbose", 0, NULL, 'v' },
		{ NULL, 0, NULL, 0 } /* Required at end of array. */
	};

	/* O nome do arquivo para receber o output. Ou NULL para standard ouput */
	const char* output_filename = NULL;

	/* Mostrar verbose ou não */
	int verbose = 0;

	/* Lembrar o nome do programa para incorporar nas mensagens.
	   O nome do programa é guardado em argv[0] */
	program_name = argv[0];

	do{
		next_option = getopt_long(argc, argv, short_options, long_options, NULL);

		switch(next_option)
		{
		case 'h':	/* -h or --help */
			/* User has requested usage information. Print it to standard
			output, and exit with exit code zero (normal termination).*/
			print_usage(stdout, 0);

		case 'o':	/* -o or --output */
					/* This option takes an argument, the name of the output file. */
			output_filename = optarg;
			break;

		case 'v': /* -v or --verbose */
			verbose = 1;
			break;

		case '?': /*The user specified an invalid option. */
				  /* Print usage information to standard error, and exit with exit
				     code one (indicating abnormal termination). */
			print_usage(stderr, 1);

		case -1: /* Acabaram as opções */
			break;

		default:  /* Algo inesperado aconteceu */
			abort();
		}
	}
	while(next_option != -1);

	/* Done with options. OPTIND points to first nonoption argument.
	For demonstration purposes, print them if the verbose option was
	specified. */
	if(verbose){
	int i;
	for(i = optind; i < argc; ++i)
		printf("Argument: %s\n", argv[i]);
	}
	
	/* Implementar main program */

	return 0;
}