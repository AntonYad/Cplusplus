#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
	umask(0);
	mkfifo("./fifo", 0664);

	int fd = open("./fifo", O_RDONLY);

	char buff[256];;
	while (1)
	{
		ssize_t ret = read(fd, buff, sizeof(buff)-1);
		if (ret>0)
		{
			buff[ret] = 0;
			printf("client %s", buff);
		}
		else if (ret == 0)
		{
			printf("is empty");
			break;
		}
	}
}
