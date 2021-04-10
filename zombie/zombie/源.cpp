#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid = fork();
	if (fork == 0)
	{
		sleep(5);
		exit(0);
	}
	wait(NULL);
	while (1)
	{
		printf("------------\n");
		sleep(1);
	}
	return 0;
}