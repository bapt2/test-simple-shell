#include <unistd.h>
#include <stdio.h>

extern char **environ;

int main()
{
	unsigned int i = 0;

	while(environ[i])
	{
		printf("%s\n", environ[i++]); /* prints in form of variable=value*/
	}
	return (0);
}
