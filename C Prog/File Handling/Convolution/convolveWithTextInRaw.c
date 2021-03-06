#include <stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define r 64
#define c 64

void writeFile(FILE *fp1)
{
    int i,j;
    
    for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           unsigned char ch = ('a'+j)%10;
           fwrite(&ch,1,1,fp1);
           printf("%u ",ch);
       }
    }    
}

void readFile(FILE *fp1)
{
    int i,j;
    
    for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           unsigned char ch;
           fread(&ch,1,1,fp1);
           printf("%u ",ch);
       }
    }    
}

int main()
{
    FILE *fp1,*fp2;
    unsigned char **buff;
    int i,j,k,l;
    int kernel[3][3] = {{1,0,-1},
                        {2,0,-2},
                        {1,0,-1}};
    
    fp1 = fopen("writefile.raw","rb");
    if(fp1==NULL)
    {printf("Error in opening the source file!");return 0;}
    else
    {
        fp2 = fopen("inverted.raw","wb");
        if(fp2==NULL)
        printf("Error in creating new file!");

        //fseek(fp1,0,SEEK_END);
        //int fileLen = ftell(fp1);
        //fseek(fp1,0,SEEK_SET);

        /*dynamically allocating 2D array*/
        buff = (unsigned char**)malloc(sizeof(char*)*r);
        for(i=0;i<r;i++)
            buff[i] = (char *)malloc(sizeof(char)*c);
            
        if(buff == NULL)
        {printf("Error in malloc!!");exit(0);}

       writeFile(fp1);
        
      fseek(fp1,0,SEEK_SET);
        
       printf("\n:::::::::::Reading from File:::::::::::\n");
       /*copying data in buff*/
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
              unsigned char ch;
              fread(&ch,1,1,fp1);
              //printf("%u ",ch);
              buff[i][j] = ch;
           }
       }
    
    //printf("\n:::::::::File Content::::::::::\n");fseek(fp1,0,SEEK_SET);
    //readFile(fp1);
    
    printf("\n:::::::::buff Content::::::::::\n");
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
               printf("%u ",buff[i][j]);
           }
       }
        
        
        
        for(i=1;i<r-1;i++)
        {
            for(j=1;j<c-1;j++)
            {
                int sum=0;
                for(k=0;k<3;k++)
                {
                    for(l=0;l<3;l++)
                    {
                        sum += kernel[k][l] * buff[i-1+k][j-1+l]; 
                    }
                }
                buff[i][j] = sum;
            }
        }
        
        printf("\n:::::::::buff Content after kernel::::::::::\n");
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
               printf("%u ",buff[i][j]);
           }
       }
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}
