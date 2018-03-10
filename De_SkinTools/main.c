#include "stdio.h"
#include <string.h>
#include <memory.h>
#define MAGIC_SIZE 9



int main(int argc,char *argv[])
{

    printf("\nBIN文件提取工具V1.0\n");
    printf("\n本软件不得用于商业用途，仅做学习交流\n");
    unsigned char Bin_Addr[4]= {0,0,0,0};
    unsigned char ZUI_magic[MAGIC_SIZE]= {0XCC,0XCC,0XCC,0XCC,0XCC,0XCC,0XCC,0XCC,0XCC};
    unsigned char BMP_magic[5]= {0X4D,0X53,0X54,0X00,0X00};
    unsigned char temp[MAGIC_SIZE];
    long file_size;
    unsigned long  pos=0;
    unsigned long  bmp_lzss_addr=0;
    unsigned long  bmp_lzss_size=0;
    unsigned char  Flag=0;
    unsigned char *mem_fp;
    unsigned long  Total_BMP_num=0;
    unsigned int   BMP_index;
    unsigned int BMP_H=0;
    unsigned int BMP_V=0;
    unsigned long BMP_Size=0;
    unsigned long Size_Info_Base=0;
    unsigned long HV_Info_Addr=0;
    unsigned long LZSS_BMP_Addr=0;
    FILE *fp=NULL;
    FILE *BMP_LZSS_fp=NULL;
    if(argc==2)
    {
        fp=fopen(argv[1],"rb");
    }
    else
    {
        fp=fopen("TEMP.bin","rb");
    }


    //getchar();
    //system("mkdir bmp");
    fseek(fp,0L,SEEK_END);
    file_size=ftell(fp);
    mem_fp=(unsigned char*)malloc(file_size);
    fseek(fp,pos,SEEK_SET);
    fread(mem_fp,1,file_size,fp);
    fclose(fp);
    do
    {
        pos++;
        Flag=((ZUI_magic[0]==mem_fp[pos+0])
              &&(ZUI_magic[1]==mem_fp[pos+1])
              &&(ZUI_magic[2]==mem_fp[pos+2])
              &&(ZUI_magic[3]==mem_fp[pos+3])
              &&(ZUI_magic[4]==mem_fp[pos+4])
              &&(ZUI_magic[5]==mem_fp[pos+5])
              &&(ZUI_magic[6]==mem_fp[pos+6])
              &&(ZUI_magic[7]==mem_fp[pos+7])
              &&(ZUI_magic[8]==mem_fp[pos+8]));
        if(pos==file_size) break;
    }
    while(Flag==0);

    printf("BINFO_MAGIC: 0X%X\n",pos);



    Flag=0;
    pos=0;

    do
    {
        pos++;
        Flag=((BMP_magic[0]==mem_fp[pos+0])
              &&(BMP_magic[1]==mem_fp[pos+1])
              &&(BMP_magic[2]==mem_fp[pos+2])
              &&(BMP_magic[3]==mem_fp[pos+3])
              &&(BMP_magic[4]==mem_fp[pos+4]));
    }
    while(Flag==0);

    bmp_lzss_addr=pos;

    Bin_Addr[0]=(pos>>24)&0xff;
    Bin_Addr[1]=(pos>>16)&0xff;
    Bin_Addr[2]=(pos>>8)&0xff;
    Bin_Addr[3]=(pos>>0)&0xff;

    Flag=0;
    pos=0;

    do
    {
        pos++;
        Flag=((Bin_Addr[0]==mem_fp[pos+0])
              &&(Bin_Addr[1]==mem_fp[pos+1])
              &&(Bin_Addr[2]==mem_fp[pos+2])
              &&(Bin_Addr[3]==mem_fp[pos+3]));
    }
    while(Flag==0);



    bmp_lzss_size=mem_fp[pos+4]*0x1000000+mem_fp[pos+5]*0X10000
                  +mem_fp[pos+6]*0X100 +mem_fp[pos+7];
    BMP_LZSS_fp=fopen("BMP_LZSS.bin","wb");
    printf("\nWRITE=%X",fwrite(mem_fp+bmp_lzss_addr,bmp_lzss_size,1,BMP_LZSS_fp));
    fclose(BMP_LZSS_fp);
    free(mem_fp);




//get bmp map
/////////////////////重新读出新文件////////////////////////////////////////////



    BMP_LZSS_fp=fopen("BMP_LZSS.bin","rb");
    fseek(BMP_LZSS_fp,0L,SEEK_END);
    file_size=ftell(BMP_LZSS_fp);
    mem_fp=(unsigned char*)malloc(file_size);
    fseek(BMP_LZSS_fp,0,SEEK_SET);

    printf("READ=%X",fread(mem_fp,1,file_size,BMP_LZSS_fp));

    fclose(BMP_LZSS_fp);//Read BMP Bin to memory
    //name=H*V_ADDRTotal_BMP_num
    // printf("\n0x%X%X\n",mem_fp[0x40],mem_fp[0x41]);
    Total_BMP_num=mem_fp[0x40]*0x100+mem_fp[0x41];
    printf("BMP Total Number: %d",Total_BMP_num);

    LZSS_BMP_Addr=0x42+Total_BMP_num*9;

    for(BMP_index=0; BMP_index<Total_BMP_num-1; BMP_index++)
    {

        printf("\nSTART*************%d*************START\n",BMP_index);
        BMP_Size=0;
        BMP_H=mem_fp[0X43+BMP_index*4]+mem_fp[0X44+BMP_index*4];
        BMP_V=mem_fp[0X45+BMP_index*4]+mem_fp[0X46+BMP_index*4];
        Size_Info_Base=mem_fp[0x04]*0x1000000+mem_fp[0x05]*0x10000+mem_fp[0x06]*0x100+mem_fp[0x07];        BMP_Size=mem_fp[Size_Info_Base+1+BMP_index*4]*0x10000
                 +mem_fp[Size_Info_Base+2+BMP_index*4]*0x100+mem_fp[Size_Info_Base+3+BMP_index*4];

      #if 0
        printf("BMP_LZSS_ADDR: %X\n",bmp_lzss_addr);
        printf("BMP_LZSS_SIZE:0X%X",bmp_lzss_size);
        printf("\nWrite Successful\n");
        printf("\nBMP_H=%d",BMP_H);
        printf("\nBMP_V=%d",BMP_V);
        printf("\nSize_Info_Base=0x%X",Size_Info_Base);
        printf("\nBMP_LZSS_size=0x%X",BMP_Size);
        printf("\nHV_Info_Addr=0x%X",HV_Info_Addr);
        printf("\nBMP_START_ADDR: %X",LZSS_BMP_Addr);
        printf("\nBMP_END_ADDR: %X",LZSS_BMP_Addr+BMP_Size);
      #endif

        FILE *TEMP_LZSS_fp;

        TEMP_LZSS_fp=fopen("TEMP_BMP_LZSS.bin","wb");
        printf("\nWRITE %d=%X\n",BMP_index,fwrite(mem_fp+LZSS_BMP_Addr,BMP_Size,1,TEMP_LZSS_fp));

        LZSS_BMP_Addr+=BMP_Size;

        fclose(TEMP_LZSS_fp);






        char cmd[200];



        system("7lzma.exe d 0  TEMP_BMP_LZSS.bin BMP.rgb");

        sprintf(cmd,"ffmpeg.exe -s %dX%d  -pix_fmt rgb555le -i BMP.rgb -s %dX%d  ./bmp/%d_%d_%d.bmp"
                ,BMP_H,BMP_V,BMP_H,BMP_V,BMP_index,BMP_H,BMP_V);


        system(cmd);






        // getch();
    }
    free(mem_fp);
  return 0;

}


