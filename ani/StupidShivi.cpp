#include<stdio.h>
#include<stdlib.h>

int main (int argc , char * argv [] ){

        // argv[1] = 1.jpg

        FILE *fp1;
        FILE *fp2;
        unsigned char *buffer;
        unsigned long fileLen;

        //Open file
        fp1 = fopen("C:\\Users\\h118442\\Desktop\\gaddhashivi.bmp", "rb");
		//fp1 = fopen("C:\\Users\\h118442\\Desktop\\temp.bmp", "rb");
        if (!fp1)
        {
                //fprintf(stderr, "Unable to open file %s", argv[1]);
                return 0;
        }
        fp2 = fopen("C:\\Users\\h118442\\Desktop\\tempbgh.bmp","wb");
        if(fp1==NULL){printf("Error in opening the file!");return 0;}
        //Get file length
        //fseek(file, 0, SEEK_END);
        //fileLen=ftell(file);
        //fseek(file, 0, SEEK_SET);

        //Allocate memory
        //buffer=(char *)malloc(fileLen);
        /*if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return 1;
        }*/
       
       unsigned char a;
	   int i = 0;
       while(1)
       {
           a = fgetc(fp1);
		   i++;
		   printf("%u",a);

		   if(!feof(fp1))
			{
				if(i>172)
				{
				   if(a == 0)
				   {
						  printf("%u",a);
						   //if(a == '\n')
						   //{printf("new ");fputc(a,fp2);}
              
						   //else 

						   unsigned char g = 0xff;
							fputc(g,fp2);
							continue;
				  
				   }

				   fputc(0,fp2);
				   continue;
				}
			   fputc(a,fp2);
			}
		 else
			break;
       }
        return 0;
}