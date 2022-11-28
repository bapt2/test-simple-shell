#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(void)
{
	int pid_t;

       pid_t = getppid();
       printf("%d\n", pid_t);
       return (0);
}
