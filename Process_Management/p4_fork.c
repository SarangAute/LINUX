#include<stdio.h>
#include<unistd.h>

int main(){
	//printf("Hello");	//no output '\n'is absent so it will be stored
				// in buffer and while starts execution
	printf("Hello\n");	
	while(1);
}
