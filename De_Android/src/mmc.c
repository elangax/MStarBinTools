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
    char cmd[200];
    FILE *fp=NULL;
    FILE *TEMP_fp;
    printf("mmc ");
   if(argc==6)
   {
    //�����Ƴ�����bin�ļ�������Ϊ������ʽ
   if(!strcmp(argv[1],"write.p"))
   {
    printf("write.p");
    rename(argv[4],argv[3]);
   }

   if(!strcmp(argv[1],"unlzo"))//��ѹ����
   {
    printf("unlzo");
        sprintf(cmd,"lzop -q -f -d %s -o %s"
                ,argv[3],argv[4]);//����һ���ļ���ѹ
        printf("\n%s\n",cmd);
        system(cmd);
   }
   
   if(!strcmp(argv[1],"unlzo.cont"))//��ѹ�����
   {
    printf("unlzo");
    rename(argv[4],argv[3]);
    sprintf(cmd,"lzop -q -f -d %s -o %s"
                ,argv[3],"lzo_temp");//���ڶ����ļ���ѹ����ʱ�ļ�
        printf("\n%s\n",cmd);
        system(cmd);
   sprintf(cmd,"copy /Y /b %s+%s %s"
                ,argv[4],"lzo_temp",argv[4]);//���ڶ����ļ���ѹ����ʱ�ļ�
        printf("\n%s\n",cmd);
        system(cmd);
   }

   }
}



