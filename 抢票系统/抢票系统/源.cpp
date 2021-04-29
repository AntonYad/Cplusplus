#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
int n = 1000;
pthread_mutex_t lock;
void* ticket(void* arg)
{
	char* id = (char*)arg;
	sleep(1);
	while (1)
	{
		usleep(1000);
		pthread_mutex_lock(&lock);
		if (n>0)
		{
			usleep(1000);
			printf("thread_id:%s,ticket:%d\n", id, n);
			n--;
			pthread_mutex_unlock(&lock);
		}
		else{
			pthread_mutex_unlock(&lock);
			break;
		}

	}
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	pthread_t t3;
	pthread_t t4;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&t1, NULL, ticket, "thead 1");
	pthread_create(&t2, NULL, ticket, "thead 2");
	pthread_create(&t3, NULL, ticket, "thead 3");
	pthread_create(&t4, NULL, ticket, "thead 4");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_mutex_destroy(&lock);
}
