#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{

	int fd = open("./fifo", O_WRONLY);
	char buff[256];
	while (1)
	{
		printf("please enter");
		fflush(stdout);
		ssize_t s = read(0, buff, sizeof(buff)-1);
		if (s>0)
		{
			buff[s] = 0;
			write(fd, buff, s);
		}
	}
}