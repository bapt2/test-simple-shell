#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *
 *
 **/
int main(int ac __attribute__((unused)), char **av)
{
	char *_string;
	char *delim = "' ', ',', '.', '-'";
	ssize_t read;

        printf("$ ");

        read = getline(&(*av),(size_t *)&ac, stdin);
                if (read != -1)
		{
        		_string = strtok((char *)read, delim);
			while (_string != NULL)
			{
				printf("%s\n", _string);
				_string = strtok (NULL, delim);
			}
		}
		return (0);
}

