#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(void)
{
	char *str[] = {"_direc", "/usr/", NULL};
	char *envp[]= {"_direc", NULL};

	if (execve(str[0], str, envp) == -1)
		perror("Error: oh, un souci avec le Path");
	return (0);
}
