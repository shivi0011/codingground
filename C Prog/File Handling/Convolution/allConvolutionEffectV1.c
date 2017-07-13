
#include <stdio.h>
#include<stdlib.h>

#define r 512
#define c 512

int main()
{
    FILE *fp1,*fp2;
    unsigned char **buff;
    //unsigned char buffCopy[512][512];
    unsigned char **buffCopy;
    int i,j,k,l;
    int kernel[3][3] = {{1,0,-1},         //horizontal Convolution
                        {2,0,-2},
                        {1,0,-1}};
    
    
    /*int kernel[3][3] = {{0,-1,0},           //sharpen Convolution
                        {-1,5,-1},
                        {0,-1,0}};
    */
    
    /*int kernel[3][3] = {{0,1,0},            //edge detection
                        {1,-4,1},
                        {0,1,0}};
    */
    
    /*int kernel[3][3] = {{1,0,-1},           //edge detection with slight difference
                        {0,0,0},
                        {-1,0,1}};
    */
    
    /*float kernel[3][3] = {{1/16,2/16,1/16},       //check how to perform division as it has to be float
                        {2/16,4/16,2/16},
                        {1/16,2/16,1/16}};
    */
    
    fp1 = fopen("lena_gray.raw","rb");
    if(fp1==NULL)
    {printf("Error in opening the source file!");return 0;}
    else
    {
        fp2 = fopen("edgeDetectionConv1.raw","wb");
        if(fp2==NULL)
        printf("Error in creating new file!");

        fseek(fp1,0,SEEK_END);
        int fileLen = ftell(fp1);
        fseek(fp1,0,SEEK_SET);
        printf("SIze of file %d\n",fileLen);
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
              //if(i==4 && j==4)
              //printf(">>%d<<",ch);
              
              buff[i][j] = ch;
              buffCopy[i][j]=ch;
           }
       }
        
        
        for(i=1;i<r-1;i++)
        {
            for(j=1;j<c-1;j++)
            {
                unsigned char sum=0;     //should it be char or int...whats difference
                for(k=0;k<3;k++)
                {
                    for(l=0;l<3;l++)
                    {
                        //printf(" kernel[%d][%d] * buff[%d][%d] = ",k,l,i-1+k,j-1+l);
                        //printf("%d * %d\n",kernel[k][l], buff[i-1+k][j-1+l]);
                        sum += kernel[k][l] * buff[i-1+k][j-1+l]; 
                        
                    }
                    //printf("Sum = %d\n",sum);
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
               //if(j<20)
               //printf("%u ",a);
           }
           //if(i>5)
           
        }    
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}
