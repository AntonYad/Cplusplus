#include<stdio.h>
#include<ctype.h>
#include<stdilb.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<wait.h>

#define SIZE 256
#define NUM 16

void redirect(char *cmd)
{
	int fd = -1;
	int redirect_count = 0;
	char *ptr = cmd;
	char *file = NULL;
	while (*ptr)
	{
		if (*ptr = '>')//重定向
		{
			*ptr++ = '\0';
			redirect_count++;
			if (*ptr == '>')//追加重定向
			{
				*ptr++ = '\0';
				redirect_count++;
			}
			while (*ptr != '\0' && isspace(*ptr))
			{
				*ptr++;
			}
			file = ptr;
			while (*ptr != '\0' && !isspace(*ptr))
			{
				*ptr++;
			}
			*ptr = '\0';
			if (1 == redirect_count)

			{
				fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0664);
			}
			else if (2 == redirect_count)
			{
				fd = open(file, O_CREAT | O_WRONLY | O_APPEND, 0664);
			}
			dup2(fd, 1);
			close(fd);
		}
		ptr++;
	}
}
