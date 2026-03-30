#include<stdio.h>
#include<unistd.h>

int main(){
	printf("Hi\n");
	fork();
	fork();
	printf("Hello\n");
}
