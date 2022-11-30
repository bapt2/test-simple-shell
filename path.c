#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int look_for_file_in_path(int argc, char **argv)
{
	char *path = "/bin/";
/*	char *str;*/

	printf("$ ");

	if (getline(&(*argv),(size_t *)&argc, stdin) != -1)
		printf("%s\n", *argv);
	printf("%s\n", path);





	return (0);
}
