/*pthread_join will wait till the thread terminates and then wherever
 that call is present then it will proceed program after a call*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void *thread1(void *);
void *thread2(void *);
int main()
{
	pthread_t t1,t2;
	void **ptr1, **ptr2;
	printf("In main() process...\n");
	pthread_create(&t1,0,thread1,0);
	pthread_create(&t2,0,thread2,0);
	pthread_join(t1,(int*)&ptr1);
	pthread_join(t2,(int*)&ptr2);
	printf("in main(), ptr = %d\n",(int*)ptr1);
	printf("in main(), ptr = %d\n",(int*)ptr2);
	printf("main process is exit\n");
}

void *thread1(void *p)
{
	printf("in thread1 5 seconds delay\n");
	sleep(5);
	printf("thread-1 is exit\n");
	pthread_exit("Bye Bye thread-1");
}
void *thread2(void *p)
{
	printf("in thread2 7 seconds delay\n");
	sleep(7);
	printf("thread-2 is exit\n");
	pthread_exit("Bye Bye thread-2");
}
