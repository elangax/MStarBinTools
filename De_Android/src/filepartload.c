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
        printf("��ʼ��ַ=%u\n",StartAddr);
        printf("���ݳ���=%u\n",DataLen);
        mem_fp=(unsigned char*)malloc(DataLen);//�������ݳ���

        fp=fopen("MstarUpgrade.bin","rb");
        fseek(fp,StartAddr,SEEK_SET);//�ƶ�����ʼ��ַ
        fread(mem_fp,DataLen,1,fp);//��ȡ���ݵ�������
        fclose(fp);

        TEMP_fp=fopen(argv[4],"wb");//д��
        fwrite(mem_fp,DataLen,1,TEMP_fp);
        fclose(TEMP_fp);
        free(mem_fp);
    }
}



