#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	while (1)
	{
		//等待标准输入
		char buf[1024] = { 0 };
		fgets(buf, 1023, stdin);
		buf[strlen(buf) - 1] = '\0';
		char* argv[32] = { NULL };
		int argc = 0;
		char *ptr = buf;
		while (*ptr != '\0')
		{
			if (*ptr != ' ')
			{
				argv[argc] = ptr;
				argc++;
				while (*ptr != ' ' && *ptr != '\0')
				{
					ptr++;
				}
				*ptr = '\0';
			}
			ptr++;
		}
		argv[argc] = NULL;
		pid_t pid = fork();
		if (pid == 0)
		{
			int ret = execvp(argv[0], (char**)argv);
			if (ret<0)
			{
				perror("execvp error");
				return -1;
			}
			exit(0);
		}
		wait(NULL);

	}
}
