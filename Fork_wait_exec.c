#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>

void fun(pid_t pid, pid_t val_id)
{
	char *_path = "/bin/ls";
	char *argv[] = {_path, "-l", "/tmp", NULL};

	if (pid == -1)
	{
		perror("Error in creating a new child process");
	}
	if (pid == 0)
	{
		printf("child  process  ID: %d\n\n", val_id);
		if (execve(_path, argv, NULL) == -1)
		{
			perror("Error in executing the command");
		}
	}
	else
	{
		wait(NULL);
		printf("\nParent propcess ID: %d\n", val_id);

	}
}


int main(void)
{
	pid_t pid; /*declaration of fork*/
	pid_t val_id; /* receave the pid value*/

	pid = fork();
	val_id = getpid();
	fun(pid, val_id);

	pid = fork();
	val_id = getpid();
	fun(pid, val_id);

	pid = fork();
	val_id = getpid();
	fun(pid, val_id);

	pid = fork();
	val_id = getpid();
	fun(pid, val_id);

	pid = fork();
	val_id = getpid();
	fun(pid, val_id);
	
	return (0);
}
