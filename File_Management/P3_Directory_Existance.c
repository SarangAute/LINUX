#include<stdio.h>
#include<sys/types.h>
#include<dirent.h>
int main(int argc,char *argv[]){
          if(argc != 2)
          {
                  printf("Usage : ./a.out directory\n");
                  return 0;
          }
          DIR *dp = opendir(argv[1]);

          if(dp == NULL)
          printf("The directory doesn't exist\n");
          else
          printf("The directory is exist\n");
}
