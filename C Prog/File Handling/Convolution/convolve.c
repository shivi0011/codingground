#include <stdio.h>
#include<stdlib.h>

#define r 512
#define c 512


int main()
{
    FILE *fp1,*fp2;
    unsigned char **buff;
    int i,j,k,l;
    int tmp[3][3];
    int kernel[3][3] = {{1,0,-1},{2,0,-2},{1,0,-1}};
    
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

        /*dynamically allocating 2D array*/
        buff = (unsigned char**)malloc(sizeof(char*)*r);
        for(i=0;i<r;i++)
            buff[i] = (char *)malloc(sizeof(char)*c);
            
        if(buff == NULL)
        {printf("Error in malloc!!");exit(0);}
        
        
        while(fread(&buff,fileLen,1,fp1)==1)
        {
            //printf("%u ",ch);
            //unsigned char temp = 0xff-ch;
            fwrite(&buff,fileLen,1,fp2);
        }
        
        for(i=1;i<r-1;i++)
        {
            for(j=1;j<c-1;j++)
            {
                int sum=0;
                /*copy 3x3 into tmp array*/
                x=0;
                for(k=0;k<3;k++)
                {
                    y=0;
                    for(l=0;l<3;l++)
                    {
                        sum += kernel[k][l] * buff[i-1+x][j-1+y];   
                        
                        y++;
                    }
                    x++;
                }
                buff[i][j] = sum;
            }
        }
        
        
        
        unsigned char ch;int max=0;
        while(fread(&ch,1,1,fp1)==1)
        {
            printf("%u ",ch);
            
            if(ch>max) max = ch;
            
            unsigned char temp = 0xff-ch;
            fwrite(&temp,1,1,fp2);
           
        }
        printf("\nMax is %d\n",max);
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}

