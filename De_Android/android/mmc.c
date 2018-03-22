#include "stdio.h"
#include <string.h>
#include <memory.h>
#include "stdlib.h"
#define MAGIC_SIZE 8

int main(int argc,char *argv[])
{
    unsigned int i;
    unsigned long StartAddr;
    unsigned long DataLen;
    unsigned long file_size;
    unsigned char *mem_fp;
    FILE *fp=NULL;
    FILE *TEMP_fp;

    for(i=0; i<argc; i++)
    {

        printf("i=%d %s\n",i,argv[i]);

    }
    printf("\n参数数量:%d\n",argc);
   if(argc==6)
   {
    //将复制出来的bin文件重命名为分区格式
   if(!strcmp(argv[1],"write.p"))
   {
    printf("write.p");
    rename(argv[4],argv[3]);
   }
   }
}



