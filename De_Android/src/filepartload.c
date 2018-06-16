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
    printf("%d",argc);
    if(argc==5)
    {
        StartAddr=strtoul(argv[3],0,16);
        DataLen=strtoul(argv[4],0,16);
        printf("起始地址=%u\n",StartAddr);
        printf("数据长度=%u\n",DataLen);
        mem_fp=(unsigned char*)malloc(DataLen);//分配数据长度

        fp=fopen("MstarUpgrade.bin","rb");
        fseek(fp,StartAddr,SEEK_SET);//移动到起始地址
        fread(mem_fp,DataLen,1,fp);//读取数据到缓冲区
        fclose(fp);

        TEMP_fp=fopen(argv[4],"wb");//写入
        fwrite(mem_fp,DataLen,1,TEMP_fp);
        fclose(TEMP_fp);
        free(mem_fp);
    }
}



