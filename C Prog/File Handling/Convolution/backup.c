#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define r 512
#define c 512


using namespace std;

class myClass
{
    public:
    void convolve(FILE *fp1,FILE *fp2,unsigned char **buff,unsigned char **buffCopy,int kernel[3][3])
    {
        int i,j,k,l;
       
        /*dynamically allocating 2D array*/
        buff = (unsigned char**)malloc(sizeof(unsigned char*)*r);
        for(i=0;i<r;i++)
            buff[i] = (unsigned char *)malloc(sizeof(unsigned char)*c);
            
        if(buff == NULL)
        {printf("Error in malloc!!");exit(0);}

        buffCopy = (unsigned char**)malloc(sizeof(unsigned char*)*r);
        for(i=0;i<r;i++)
            buffCopy[i] = (unsigned char *)malloc(sizeof(unsigned char)*c);
            
        if(buffCopy == NULL)
        {printf("Error in malloc!!");exit(0);}

       
      /* printf("\n::::::::::Copying data from File to buff:::::::::::\n");*/
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
              unsigned char ch;
              fread(&ch,1,1,fp1);
       
              buff[i][j] = ch;
              buffCopy[i][j]=ch;
           }
       }
        
        for(i=1;i<r-1;i++)
        {
            for(j=1;j<c-1;j++)
            {
                unsigned char sum=0;    
                for(k=0;k<3;k++)
                {
                    for(l=0;l<3;l++)
                        sum += kernel[k][l] * buff[i-1+k][j-1+l]; 
                }
                //printf("Final update Sum = %d\n",sum);
                buffCopy[i][j] = sum;
            }
        }
        
        /*Put the buffer content into the new file*/
        for(i=0;i<r;i++)
        {
           for(j=0;j<c;j++)
           {
               unsigned char a = buffCopy[i][j];
               fwrite(&a,1,1,fp2);
           }
        }
        
        free(buff);
        free(buffCopy);
        fclose(fp1);
        fclose(fp2);
    }
};

int main()
{
    FILE *fp1,*fp2;
    unsigned char **buff;
    unsigned char **buffCopy;
    
    int hKernel[3][3] = {{1,0,-1},         //horizontal Convolution
                        {2,0,-2},
                        {1,0,-1}};
    
    
    int sharpenKernel[3][3] = {{0,-1,0},           //sharpen Convolution
                            {-1,5,-1},
                            {0,-1,0}};
    
    
    int edgeDetectKernel[3][3] = {{0,1,0},            //edge detection
                                {1,-4,1},
                                {0,1,0}};
    
    
    int edgeDetect1Kernel[3][3] = {{1,0,-1},           //edge detection with slight difference
                                {0,0,0},
                                {-1,0,1}};
    
    
    fp1 = fopen("lena_gray.raw","rb");
    if(fp1==NULL)
    {printf("Error in opening the source file!");return 0;}
    else
    {   
        char str1[50] = "hKernel";
        char str2[50] = "edgeDetection";
        //char str3[50] = "edgeDetectionV1";
        
        myClass c1,c2,c3;
        fp2 = fopen(strcat(str1,".raw"),"wb");
        if(fp2==NULL)
        printf("Error in creating new file!");
        c1.convolve(fp1,fp2,buff,buffCopy,hKernel);
        
        fp2 = fopen(strcat(str2,".raw"),"wb");
        if(fp2==NULL)
        printf("Error in creating new file!");
        fp1 = fopen("lena_gray.raw","rb");
        c2.convolve(fp1,fp2,buff,buffCopy,sharpenKernel);
        
    }
    
    return 0;
}
