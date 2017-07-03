//this also not inverting the vertical pixels as they are not belonging to completely to any pixel
//every image file (ex-BMP) has a header and trailer embeded with it so while inverting the image we need not 
//to do anything to those pixels
#include<stdio.h>
#include<stdlib.h>

int main ()
{
        FILE *fp1;
        FILE *fp2;
     
        fp1 = fopen("bb.bmp", "rb");
        if (!fp1)
        {
                printf("Error in opening the file!!");
                return 0;
        }
        fp2 = fopen("neww.bmp","wb");
        if(fp1==NULL)
        {
            printf("Error in opening the file!");
            return 0;
        }
        
     unsigned char a;
	   int i = 0;

       while(1)
       {
                 a = fgetc(fp1);
                 i++;
                 printf("%u ",a);

                 if(!feof(fp1))
                 {
                    if(i>172)
                    {
                         if(a == 0)
                         {
                            printf("%u",a);

                            unsigned char g = 0xff;
                            fputc(g,fp2);
                            continue;
                         }

                         fputc(0,fp2);        //value should be in hexadecimal... 0 is same as 0x00
                         continue;
                    }
                 fputc(a,fp2);            //this will be the header and trailer of BMP file which should
                }                           //not change
               else
                 break;
       }
   return 0;
}
