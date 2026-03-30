#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
	int a[5],start,end,i;
	srand(getpid());
	printf("ENTER STARTING RANGE: \n");
	scanf("%d",&start);
	printf("ENTER ENDING RANGE: \n");
	scanf("%d",&end);

	for(i=0;i<5;i++)
		a[i] = rand()%((end-start)+1)+start;

	printf("RANDOM NUMBERS ARE: \n");
	for(i=0;i<5;i++)
		printf("%d\n",a[i]);
}
