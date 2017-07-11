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
            //fwrite(&buff,fileLen,1,fp1);
        }
        
        printf("%d\n",sizeof(buff));
        
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
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}

