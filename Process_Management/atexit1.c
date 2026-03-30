#include<stdio.h>
#include<stdlib.h>

void abc();
void def();

int main(){
	printf("hi\n");
	atexit(abc);	//function registration
	atexit(def);
	printf("hello\n");
	printf("process terminated\n");
	exit(0);
	//_exit(0);
}

void abc(){
	printf("IN ABC FUN BODY\n");
	return;
}

void def(){
	printf("IN DEF FUN BODY\n");
	return;
}
