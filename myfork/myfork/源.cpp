#include<iostream>
#include<unistd.h>
#include<sys/types.h>
using namespcae std;
int main()
{
	cout << "I am process" << getpid() << endl;
	pid_t id = fork();
	if (pid<0)
	{
		cerr << "fork error" << endl;
	}
	if (pid == 0)
	{
		cout << "son" << getpid() << endl;
		//child
		//sleep(5);
	}
	else
	{
		cout << "I am father" << getpid() << "son" << id << endl;
		//parent
		//sleep(5);
	}
	return 0;
}
