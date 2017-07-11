/*As its raw image which doesn't contain the header so we dont need to skip the header part*/
#include <stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp1,*fp2;
    unsigned char *buff;
    
    fp1 = fopen("lena_gray.raw","rb");
    if(fp1==NULL)
    {printf("Error in opening the source file!");return 0;}
    else
    {
        fp2 = fopen("inverted.raw","wb");
        if(fp2==NULL)
        printf("Error in creating new file!");
        
        fseek(fp1,0,SEEK_END);
        int fileLen = ftell(fp1);
        fseek(fp1,0,SEEK_SET);
        printf("Length of file is %d\n",fileLen);

        buff = (char*)malloc(fileLen);
        if(buff == NULL)
        {printf("Error in malloc!!");exit(0);}
        
        unsigned char ch;int i=0,max=0;
        while(fread(&ch,1,1,fp1)==1)
        {
            printf("%u ",ch);
            
            if(ch>max) max = ch;
            
            unsigned char temp = 0xffff-ch;
            fwrite(&temp,1,1,fp2);
            i++;
        }
        printf("\nMax is %d\n",max);
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}

