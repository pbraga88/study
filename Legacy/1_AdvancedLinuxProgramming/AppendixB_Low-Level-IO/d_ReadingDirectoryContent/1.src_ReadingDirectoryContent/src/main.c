#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
/* Return a string that describes the type of the file system entry PATH. */


const char* get_file_type (const char* path)
{
	struct stat st;
	lstat (path, &st);
	if (S_ISLNK (st.st_mode))
		return "symbolic link";
	else if (S_ISDIR (st.st_mode))
		return "directory";
	else if (S_ISCHR (st.st_mode))
		return "character device";
	else if (S_ISBLK (st.st_mode))
		return "block device";
	else if (S_ISFIFO (st.st_mode))
		return "fifo";
	else if (S_ISSOCK (st.st_mode))
		return "socket";
	else if (S_ISREG (st.st_mode))
		return "regular file";
	else
	/* Unexpected. Each entry should be one of the types above. */
	assert (0);
}

int main(int argc, char* argv[])
{
	char* dir_path;
	DIR* dir;
	struct dirent* entry;
	char entry_path[_PC_PATH_MAX + 1];
	size_t path_len;

	if(argc >= 2)
		/* Usa o diretório especificado na chamada da aplicação */
		dir_path = argv[1];
	else
		/* Caso contrário, utiliza o diretório atual */
		dir_path = ".";

	/* Copia o caminho para o diretório em 'entry_path' */
	strncpy(entry_path, dir_path, sizeof(entry_path));
	path_len = strlen(dir_path);
	/* Caso o caminho para diretório não termine com '/', adicione */
	if(entry_path[path_len -1] != '/')
	{
		entry_path[path_len] = '/';
		entry_path[path_len + 1] = '\0';
		++path_len;
	}

	/* Inicia a operação de listagem do diretório passado na linha de comando */
	dir = opendir(dir_path);
	/* Faz o loop por todos os diretórios */
	while((entry = readdir(dir)) != NULL)
	{
		const char* type;
		/* Cria o diretório anexando 'entry name' à 'path name' */
		strncpy(entry_path + path_len, entry->d_name, sizeof(entry_path) - path_len);
		/* Determina o tipo da entrada*/
		type = get_file_type(entry_path);
		/* Printa o tipo e o caminho para a entrada */
		printf("%-18s: %s\n",type, entry_path);
	}
	/* All done*/
	closedir(dir);

	return 0;
}