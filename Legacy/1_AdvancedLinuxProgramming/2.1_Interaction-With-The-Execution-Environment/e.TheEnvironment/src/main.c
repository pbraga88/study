#include <stdio.h>

/* A variável ENVIRON possui as variáveis de ambiente */
extern char** environ;

int main()
{
        char** var;
        for (var = environ; *var != NULL; ++var)
                printf("%s\n", *var);

        return 0;
}
