#include "stdio.h"
#include <string.h>
#include <memory.h>
#include "stdlib.h"
#define MAGIC_SIZE 8

int main(int argc,char *argv[])
{
    unsigned char SCRIPT_magic[MAGIC_SIZE]= {'p','r','i','n','t','e','n','v'};
    unsigned long file_size;
    unsigned long  pos=0;
    unsigned char  Flag=0;
    unsigned char *mem_fp;
    FILE *fp=NULL;
    FILE *Script_fp;
    if(argc==2)
    {
        fp=fopen(argv[1],"rb");
    }
    else
    {
        fp=fopen("MstarUpgrade.bin","rb");
    }
    fseek(fp,0L,SEEK_END);
    file_size=ftell(fp);
    mem_fp=(unsigned char*)malloc(file_size);
    fseek(fp,0,SEEK_SET);
    fread(mem_fp,1,file_size,fp);
    fclose(fp);
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
    Script_fp=fopen("script.bat","wb");
    fwrite(mem_fp,pos,1,Script_fp);
    fclose(Script_fp);
    CRC_value = *((unsigned long *)(mem_fp+file_size - FULL_FILE_CRC_OFFSET));
    printf("FILE_SIZE: %lX\n",file_size);
    printf("  BIN_CRC:%lX\n",CRC_value);
    free(mem_fp);

    system("script.bat");
    system("cuscmd.bat");
}



