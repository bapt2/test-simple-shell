#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main(int argc, char **argv)
{
	int notfound = 0;
	char *cmd = argv[1];
	char *token, *path = NULL, *path_copy = NULL;
	const char *temp = getenv("PATH");
	struct stat st;

	(void)argc;

	/* COPIE de PATH*/
	path_copy = malloc(strlen(temp) + 1);
	strcpy(path_copy, temp);

	token = strtok(path_copy, ":");
	while(token)
	{
		path = malloc(sizeof(char) * (strlen(token) + strlen(cmd) + 1));
		strcat(path, token);
		strcat(path, "/");
		strcat(path, cmd);
		if (stat(path, &st) == 0)
		{
			printf("%s\n", path);
			notfound = 1;
			break;
		}
		token = strtok(NULL, ":");
	}
	if (notfound == 0)
		printf("NOT FOUND\n");
	return (0);
}
