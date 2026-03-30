//raise : send signal to the caller 
#include<stdio.h>
#include<signal.h>

int main(){
	printf("Hi...\n");
	raise(9);
	printf("hello\n");
	printf("By...\n");
	while(1);
}
