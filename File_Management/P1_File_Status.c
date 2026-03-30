#include<stdio.h>
#include<sys/stat.h>
int main(int argc,char * argv[]){
      struct stat v;
      if(argc != 2) {
         printf("./a.out file name..\n");
         return 0;
      }  
     if(stat(argv[1],&v)<0){
          perror("stat");
          return 0;
     }
          printf("size : %ld\n",v.st_size);
          printf("ino  : %ld\n",v.st_ino);
          printf("mode  : %o\n",v.st_mode);
          printf("hardlinks  : %ld\n",v.st_nlink);
  }
