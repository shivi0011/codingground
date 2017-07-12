/*Working Convolution filter with numbers in raw format*/
#include <stdio.h>
#include<stdlib.h>

#define r 512
#define c 512

void writeFile(FILE *fp1)
{
    int i,j;
    
    for(i=0;i<r;i++)
    {
       for(j=0;j<c;j++)
       {
           unsigned char ch = ('a'+j)%10;
           fwrite(&ch,1,1,fp1);
           //printf("%u ",ch);
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
           //printf("%u ",ch);
       }
    }    
}

int main()
{
    FILE *fp1,*fp2;
    char **buff;
    int i,j,k,l;
    int kernel[3][3] = {{1,0,-1},
                        {2,0,-2},
                        {1,0,-1}};
    
    fp1 = fopen("writefile.raw","wb");
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
        buff = (char**)malloc(sizeof(char*)*r);
        for(i=0;i<r;i++)
            buff[i] = (char *)malloc(sizeof(char)*c);
            
        if(buff == NULL)
        {printf("Error in malloc!!");exit(0);}

       writeFile(fp1);
        
      fseek(fp1,0,SEEK_SET);
        
       printf("\n::::::::::Reading from File:::::::::::\n");
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
           printf("\n");
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
                        printf(" kernel[%d][%d] * buff[%d][%d] = ",k,l,i-1+k,j-1+l);
                        printf("%d * %d\n",kernel[k][l], buff[i-1+k][j-1+l]);
                        sum += kernel[k][l] * buff[i-1+k][j-1+l]; 
                        
                    }
                    printf("Sum = %d\n",sum);
                }
                printf("Final update Sum = %d\n",sum);
                buff[i][j] = sum;
            }
        }
        
        printf("\n:::::::::buff Content after kernel::::::::::\n");
       for(i=0;i<r;i++)
       {
           for(j=0;j<c;j++)
           {
               printf("%d ",buff[i][j]);
           }
           printf("\n");
       }
        
        fclose(fp1);
        fclose(fp2);
    }
    
    return 0;
}






7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 -8 0 14 20 30 48 82 -108 22 24 26 68 -106 36 62 112 -46 -108 22 24 26 68 -106 36 62 112 -46 -108 22 24 8                                                    
7 1 -12 -38 -98 24 -14 116 22 -104 26 -12 116 14 110 -120 114 -76 22 -104 26 -12 116 14 110 -120 114 -76 22 -104 44 8                                         
7 13 73 -18 -104 -44 66 84 118 -40 66 22 26 64 0 -12 -78 -76 118 -40 66 22 26 64 0 -12 -78 -76 118 -58 10 8                                                   
7 -72 -105 -27 -34 10 -118 -44 22 80 80 -76 70 -84 -98 -126 58 -92 22 80 80 -76 70 -84 -98 -126 58 -92 40 -84 4 8                                             
7 106 -81 29 15 106 0 104 70 66 14 18 52 22 80 -4 -52 -80 -90 2 -114 18 52 22 80 -4 -52 -98 38 96 82 8                                                        
7 82 -7 -104 -35 -63 122 -94 92 -32 -34 -126 8 -6 8 -116 90 -50 60 -128 -34 2 8 -6 8 -116 108 114 20 -20 30 8                                                 
7 8 -46 -58 93 21 63 -112 -44 22 120 -78 -12 -18 68 46 16 50 -92 -106 -104 -14 -12 -18 68 28 72 -36 48 70 94 8                                                
7 47 -88 -53 65 -104 -85 -75 -42 -8 66 -12 -76 30 -10 24 34 -92 -42 -88 -30 84 -76 30 8 4 62 -120 -104 -14 16 8                                               
7 89 30 -87 127 -116 -15 -85 5 -114 14 -106 10 -40 -80 44 -62 -60 118 -48 -30 -34 -6 -90 96 -126 118 -122 -108 -96 24 8      .




7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8                                                                                               
7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8   

we are simultaneously updating the values in the same buff matrix so u need to consider those values not the above one.

{{1,0,-1},
{2,0,-2},
{1,0,-1}};
