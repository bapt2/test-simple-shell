#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	while (1)
	{
		size_t len_str = 0;
		char *_str = NULL;
		char *token;

		printf("prompt: ");

		if (getline(&_str, &len_str, stdin) == -1)
			exit(EXIT_FAILURE);

		token = malloc(sizeof(_str) * len_str);
		if (token != NULL)
		{
			token = strtok(_str, " ");
			printf("%s\n", token);

			while(token)
			{
				token = strtok(NULL, " ");
				if (token != NULL)
					printf("%s\n", token);
			}
		}
		free(token);
	}
	return (0);
}
