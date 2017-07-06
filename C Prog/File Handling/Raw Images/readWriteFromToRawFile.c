#include <stdio.h>
#include <stdlib.h>

void writeInRawFile(FILE *fpw)
{
        int i,num;
        for(i=0;i<10;i++)
        {
            num = i;
            fwrite (&num, sizeof(int), 1, fpw);
        }  
}

void readFromRawFile(FILE *fpr)
{
    int num;
     while(fread(&num,sizeof(int),1,fpr)==1)
                printf("%d ",num);
            
    
}

int main()
{
    FILE *fpw;
        fpw = fopen ("numbers.raw", "wb");
         if(fpw==NULL)
         {printf("Error in writing the file!!");return 0;}
         else
         {
                writeInRawFile(fpw);
                fclose(fpw);  
         } 
          
          
         FILE *fpr;
         fpr = fopen("numbers.raw","rb");
         if(fpr==NULL)
         {printf("Error in reading the file!!");return 0;}
         else
         {
             readFromRawFile(fpr);
             fclose(fpr);
         }
          

    return 0;
}

