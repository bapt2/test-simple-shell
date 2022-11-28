#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


/**
 *
 *
 *
 *
 **/
int main(int ac, char **av)
{
	ssize_t read;

	printf("$ ");

	read = getline(&(*av),(size_t *)&ac, stdin);
		if (read != -1)
			printf("%s\n", *av);
	return (0);
}
