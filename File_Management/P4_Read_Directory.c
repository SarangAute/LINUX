#include<stdio.h>
#include<dirent.h>
int main(int argc,char*argv[])
{
        if(argc != 2) {
        printf("Usage : ./a.out file\n");
        return 0;
        }
        DIR *dp;
        struct dirent *p;
        dp = opendir(argv[1]);
        if(dp == NULL)
        {
             perror("opendir\n");
             return 0;
        }
        while(p=readdir(dp))
        printf("%s  ",p->d_name);
        printf("\n");
}
