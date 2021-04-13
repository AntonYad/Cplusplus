#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<unistd.h>
#include<time.h>
int main()
{
	int pipefd[2] = { 0 };
	pipe(pipefd);
	pid_t id = fork();
	if (id == 0)
	{
		close(pipefd[1]);
		char buff[256];
		ssize_t ret = read(pipefd[0], buff, sizeof(buff)-1);
		if (ret>0)
		{
			buff[ret] = 0;
			printf("buf=%s\n", buff);
		}

	}
	else
	{
		close(pipefd[0]);
		const char *msg = "I am father\n";
		write(pipefd[1], msg, strlen(msg));
		close(pipefd[1]);
	}
	return 0;
}
