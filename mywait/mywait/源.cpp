#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
	pid_t pid = fork();
	if (pid<0)
	{
		printf("creat false");
	}
	if (pid == 0)
	{
		//child
		printf("I am child process");
		sleep(5);
		exit(13);
	}
	else
	{
		//father
		int st;
		//wait(&st);
		int ret = waitpid(pid, &st, 0);
		if (ret > 0 && (st & 0X7F) == 0)
		{
			// Õý³£ÍË³ö
			printf("st:%d\n", st);
			printf("child exit code:%d\n", (st >> 8) & 0XFF);
		}
		else if (ret>0)
		{
			printf("child exit signal:%d\n", st & 0X7F);
		}
	}
}
