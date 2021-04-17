#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
int main()
{
	// int fd=open("bite.txt",O_RDWR|O_CREAT,0777);
	// write(fd,"i like linux!\n",14);
	// char buff[1024];
	// read(fd,buff,14);
	// printf("%s",buff);
	// close(fd);

	FILE* fp = fopen("mybite", "w+r");
	char buff[1024];
	const char *file1 = "whbNB\n";
	fwrite(file1, strlen(file1), 1, fp);//stdout
	fread(buff, 1, strlen(file1), fp);
	fclose(fp);
	return 0;
}
