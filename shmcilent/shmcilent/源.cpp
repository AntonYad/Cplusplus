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
	printf("key:%p\n", k);
	int shm_id = shmget(k, 256, 0);
	if (shm_id<0)
	{
		perror("shmget perror");
		return -1;
	}
	printf("shmid id%d\n", shm_id);
	char *str = shmat(shm_id, NULL, 0);
	char c = 'a';
	for (; c <= 'z'; c++)
	{
		str[c - 'a'] = c;
		sleep(3);
	}
	return 0;
}
