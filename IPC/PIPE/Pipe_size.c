#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
      int count=0;
      char ch='A';
      int fd[2];
      if(pipe(fd) < 0)
      {
          perror("pipe");
          return 0;
      }
      while(write(fd[1],&ch,1) != -1)
      {
           count++;
           printf("size = %d\n",count);
      }
}
/*OUTPUT:
 	size = 65531
	size = 65532
	size = 65533
	size = 65534
	size = 65535
	size = 65536


AND STUCK INSIDE WHILE
 	*/
