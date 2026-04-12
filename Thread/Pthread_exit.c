#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void *thread1(void *);
void *thread2(void *);

int main()
{
   pthread_t t1,t2;
   printf("In main() process...\n");
   pthread_create(&t1,0,thread1,0);
   pthread_create(&t2,0,thread2,0);
   printf("main process in infinite loop\n");
   while(1);
}

void *thread1(void *p)
{
	printf("In thread1...\n");
	sleep(1);
	printf("thread1 exit\n");
	pthread_exit(0);
	printf("exited... thread1\n");	//don't execute
}
void *thread2(void *p)
{
	printf("In thread2...\n");
	sleep(2);
	printf("thread2 exit\n");
	pthread_exit(0);
	printf("Exited... thread2\n");	//don't execute
}
