#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>

pthread_mutex_t lock;
pthread_cond_t cond;
void *r1(void* arg)
{
	char* name = (char*)arg;
	while (1)
	{
		pthread_cond_wait(&cond, &lock);
		printf("liveing\n");
	}
}
void* r2(void* arg)
{
	char *name = (char*)arg;
	while (1)
	{
		sleep(2);
		pthread_cond_signal(&cond);
	}
}
int main()
{
	pthread_t t1;
	pthread_t t2;
	pthread_mutex_init(&lock, NULL);
	pthread_create(&t1, NULL, r1, "thead 1");
	pthread_create(&t2, NULL, r2, "thead 2");
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);

}
