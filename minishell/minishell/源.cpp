#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{
	char cmd[256];
	const char *cmd_line = "[anton@VM-centos]#";
	while (1)
	{
		cmd[0] = 0;
		printf("%s", cmd_line);
		fgets(cmd, 256, stdin);
		cmd[strlen(cmd) - 1] = '\0';
		char *args[16];
		args[0] = strtok(cmd, " ");
		int i = 1;
		do{
			args[i] = strtok(NULL, " ");
			if (args[i] == NULL)
			{
				break;
			}
			i++;
		} while (1);
		pid_t id = fork();
		if (id<0)
		{
			perror("fork error\n");
		}
		if (id == 0)
		{
			execvp(args[0], args);
			exit(1);
		}
		else if (id>0)
		{
			wait(NULL);
		}
	}
	return 0;
}
