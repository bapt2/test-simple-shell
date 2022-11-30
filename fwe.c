#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void _exec(pid_t pid, pid_t val_id)
{
	char *path = "/bin/ls";
	char *argv[] = {path, "-l", "/tmp", NULL};

	if (pid == -1)
	{
		perror("Error in the creation of the new child");
		return;
	}
	if (pid == 0)
	{
		printf("the ID of the child is %d\n", val_id);
		if (execve(path, argv, NULL) == -1)
		{
			perror("Error in command execution");
		}
	}
	else
	{
		wait(NULL);
		printf("The ID of the father is %d\n", val_id);
	}
}

int main(void)
{
	pid_t pid, val_id;

	pid = fork();
	val_id = getpid();
	_exec(pid, val_id);

	pid = fork();
	val_id = getpid();
	_exec(pid, val_id);

	pid = fork();
	val_id = getpid();
	_exec(pid, val_id);

	pid = fork();
	val_id = getpid();
	_exec(pid, val_id);

	pid = fork();
	val_id = getpid();
	_exec(pid, val_id);

	return (0);
}
