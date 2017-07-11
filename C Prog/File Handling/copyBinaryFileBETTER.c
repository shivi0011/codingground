#include <stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp1,*fp2;
    unsigned char *buff;
    
    fp1 = fopen("lena_color24Bit.tiff","rb");
    if(fp1==NULL)
    {printf("Error in opening the source file!");return 0;}
    else
    {
        fp2 = fopen("copied.tiff","wb");
        if(fp2==NULL)
        printf("Error in creating new file!");
        
        fseek(fp1,0,SEEK_END);
        int fileLen = ftell(fp1);
        fseek(fp1,0,SEEK_SET);
        printf("Length of file is %d\n",fileLen);

        buff = (char*)malloc(fileLen);
        if(buff == NULL)
        {printf("Error in malloc!!");exit(0);}
        
        while(fread(&buff,1,1,fp1)==1)
        {
            fwrite(&buff,1,1,fp2);
        }
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}

