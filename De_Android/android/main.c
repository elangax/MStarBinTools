#include "stdio.h"
#include <string.h>
#include <memory.h>
#include "stdlib.h"
#define MAGIC_SIZE 8

int main(int argc,char *argv[])
{
   /*filepartload 0x20200000 $(UpgradeImage) 0x4000 0x13800
     mmc write.boot 1 0x20200000 0 0x13800
     filepartload 0x20200000 $(UpgradeImage) 0x18000 0x19a000
     mmc write.p 0x20200000 MBOOT 0x19A000
     */

    unsigned char SCRIPT_magic[MAGIC_SIZE]= {'p','r','i','n','t','e','n','v'};//printenv
    long file_size;
    unsigned long  pos=0;
    unsigned char  Flag=0;
    unsigned char *mem_fp;
    FILE *fp=NULL;
    FILE *BMP_LZSS_fp;
    char *pattern_string;
    if(argc==2)
    {
        fp=fopen(argv[1],"rb");
    }
    else
    {
        fp=fopen("MstarUpgrade.bin","rb");
    }   //添加判断文件是否存在的函数

    fseek(fp,0L,SEEK_END);
    file_size=ftell(fp);
    mem_fp=(unsigned char*)malloc(file_size);
    fseek(fp,0,SEEK_SET);
    fread(mem_fp,1,file_size,fp);//读文件到内存
    fclose(fp);
    printf("FILE SIZE: %ld\n",file_size);
    do
    {
        pos++;
        Flag=((SCRIPT_magic[0]==mem_fp[pos+0])
              &&(SCRIPT_magic[1]==mem_fp[pos+1])
              &&(SCRIPT_magic[2]==mem_fp[pos+2])
              &&(SCRIPT_magic[3]==mem_fp[pos+3])
              &&(SCRIPT_magic[4]==mem_fp[pos+4])
              &&(SCRIPT_magic[5]==mem_fp[pos+5])
              &&(SCRIPT_magic[6]==mem_fp[pos+6])
              &&(SCRIPT_magic[7]==mem_fp[pos+7]));
        if(pos==file_size) break;
    }
    while(Flag==0);

    printf("SCRIPT END ADDR: 0X%X\n",pos);
    BMP_LZSS_fp=fopen("script.bat","wb");
    fwrite(mem_fp,pos,1,BMP_LZSS_fp);
    fclose(BMP_LZSS_fp);

    BMP_LZSS_fp=fopen("test.txt","r");
    //pattern_string=strstr(mem_fp,"File Partition: tvconfig");
    char str[256];

    fwrite(pattern_string,300,1,BMP_LZSS_fp);
    fclose(BMP_LZSS_fp);


    free(mem_fp);

    system("script.bat");//运行脚本
}



