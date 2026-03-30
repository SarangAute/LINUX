#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int a[5],i;
	//srand(101);
	srand(getpid());

	for(i=0;i<5;i++)
		a[i]=rand()%10+1;	//logic for number between 1-10

	printf("RANDOM GENERATED NUMBERS ARE: \n");
	for(i=0;i<5;i++)
		printf("%d\n",a[i]);
}
