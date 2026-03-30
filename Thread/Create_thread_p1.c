#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void* thread_fun (void* p){
	while(1){
		printf("MSG IN FUNCTION\n");
		sleep(1);
	}
}

int main(){
	printf("process under execution\n");
	pthread_t t1;
	pthread_create(&t1,0,thread_fun,0);
	printf("Thread ID: %u\n",t1);

	while(1){
		printf("Msg in Main()...\n");
		sleep(1);
	}
}
