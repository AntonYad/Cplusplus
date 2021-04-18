#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<sys/types.h>


#define PATHNAME "."
#define PJ_ID 0x6688

int main()
{
	key_t k = ftok(PATHNAME, PJ_ID);//´´½¨Î¨Ò»key
	int shmid = shmget(k, 256, IPC_CREAT | IPC_EXCL | 0664);
	if (shmid<0)
	{
		perror("shmget perror");
		return -1;
	}
	printf("shmid id %d\n", shmid);
	char *str = shmat(shmid, NULL, 0);
	while (1)
	{
		sleep(1);
		printf("%s\n", str);
	}
	shmdt(str);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}
