#include <stdio.h>
#include <stdlib.h>


extern char **environ;
char *_getenv(const char *name)
{
	int i, j;
	int status;

	for (i = 0; environ[i] != 0; i++)
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				status = 0;
				break;
			}
		}
		if (status)
		{
			return (&environ[i][j + 1]);
		}
	}
	return (0);
}
int main()
{
	const char *temp = _getenv("PATH");

	printf("%s\n", temp);
	return (0);
}
