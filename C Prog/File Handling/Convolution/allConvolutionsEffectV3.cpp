#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define r 512
#define c 512


using namespace std;

class myClass
{
    private:
        unsigned char **buff;
        unsigned char **buffCopy;
        
    public:
    
    /*Constructor*/
    myClass()
    {
        buff = allocateMem();
        buffCopy = allocateMem();
        printf("In constructor ..create memory")    ;
        
    }
    
    unsigned char** allocateMem()
    {
        unsigned char **temp;
        int i;
        temp = (unsigned char**)malloc(sizeof(unsigned char*)*r);
  
        for(i=0;i<r;i++)
            temp[i] = (unsigned char *)malloc(sizeof(unsigned char)*c);

        if(temp == NULL)
        {printf("Error in malloc!!");exit(0);}
        return temp;
    }
    
    
    void convolve(FILE *fp1,int kernel[3][3],char *str)
    {
        int i,j,k,l;
       
        /*dynamically allocating 2D array*/
        //buff = assignMemory();
        //buffCopy = assignMemory();
        FILE *fp2;
        fp2 = fopen(strcat(str,".raw"),"wb");
        if(fp2==NULL)
        printf("Error in creating new file!");
        
        fseek(fp1,0,SEEK_END);
        unsigned int fileLen = ftell(fp1);
        fseek(fp1,0,SEEK_SET);
       
      /* printf("\n::::::::::Copying data from File to buff:::::::::::\n");*/
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
              unsigned char ch;
              fread(&ch,1,1,fp1);
       
              buff[i][j] = ch;
              buffCopy[i][j]=ch;          //either this or memcpy u can use
           }
       }
        
        
       
        
        //memcpy(buffCopy,buff,fileLen);          //memcpy doesn't create memory
                                                //it just copies the given #f bytes to destination
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
        
        
        /*Put the buffer content char by char into the new file*/
        /*
        for(i=0;i<r;i++)
        {
           for(j=0;j<c;j++)
           {
               unsigned char a = buffCopy[i][j];
               fwrite(&a,1,1,fp2);
           }
        }*/
        
         /*Put the buffer content row by row into the new file*/
        for(i=0;i<r;i++)
        {
            unsigned char a[c];
            for(j=0;j<c;j++)
                a[j] = buffCopy[i][j];
                
            fwrite(a,sizeof(a),1,fp2);      //writing row by row
        }
        
        fseek(fp1,0,SEEK_SET);
        fclose(fp2);
    }
    
    ~myClass()
    {
        free(buff);
        free(buffCopy);
        printf("\nIn desstructor ..freed thememory")    ;
    }
};

int main()
{
  
    FILE *fp1;
    
    
    int vSobelKernel[3][3] = {{1,0,-1},         //vertical Sobel 
                              {2,0,-2},
                              {1,0,-1}};
    
    int hSobelKernel[3][3] = {{-1,-2,-1},         //horizontal Sobel
                              {0,0,0},
                              {1,2,1}};
    
    
    int weightedSobelKernel[3][3] = {{1,0,-1},         //horizontal Convolution
                                    {5,0,-5},
                                    {1,0,-1}};
                        
    int sharpenKernel[3][3] = {{0,-1,0},           //sharpen Convolution
                               {-1,5,-1},
                               {0,-1,0}};
    
    int edgeDetectKernel[3][3] = {{0,1,0},            //edge detection ++
                                 {1,-4,1},
                                {0,1,0}};
    
    
    int edgeDetectKernel1[3][3] = {{1,0,-1},           //edge detection with slight difference
                                {0,0,0},
                                {-1,0,1}};
    
    
    fp1 = fopen("lena_gray.raw","rb");
    if(fp1==NULL)
    {printf("Error in opening the source file!");return 0;}
    else
    {   
        char str1[50] = "weightedSobelKernel";
        char str2[50] = "sharpenKernel";
        char str3[50] = "edgeDetectKernel";
        char str4[50] = "edgeDetectKernel1";
        char str5[50] = "vSobelKernel";
        char str6[50] = "hSobelKernel";
        
        /*If we need to store the output of all the matrices then create separate objects*/
        myClass obj;
        
       obj.convolve(fp1,vSobelKernel,str5);
        
       obj.convolve(fp1,hSobelKernel,str6);
        
        obj.convolve(fp1,weightedSobelKernel,str1);
        
        obj.convolve(fp1,sharpenKernel,str2);

        obj.convolve(fp1,edgeDetectKernel,str3);
        
       obj.convolve(fp1,edgeDetectKernel1,str4);
        
        fclose(fp1);
    }
    
    return 0;
}
