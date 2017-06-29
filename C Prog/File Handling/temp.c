

#include <stdio.h>
#include<stdlib.h>


int main()
{
    FILE *fp;
    char data[1000];
    fp = fopen("bnw.jpg","rb+");
    if(fp==NULL)
    printf("Error in opeing!!");
    else
    {
        char ch;
        while((ch = fgetc(fp)) != EOF)
        {
            fputc(255-ch,fp);
        }
        
        fclose(fp);
    }
          
    return 0;
}



http://www.dreamincode.net/forums/topic/29852-how-to-read-and-write-file-image-bmpjpgico-and-so-on-using-c/
https://www.codingunit.com/c-tutorial-binary-file-io
http://paulbourke.net/dataformats/bitmaps/
http://www.sanfoundry.com/c-program-compare-two-binary-files/
https://stackoverflow.com/questions/31237870/reading-a-jpeg-file-byte-by-byte

http://www.it.uc3m.es/abel/as/MMC/L2/FilesDef_en.html

how can i read any image byte by byte in c file handling


Reading image file byte by byte and storing in an array
-------------------------------------------------------

int main (int argc , char * argv [] ){

        // argv[1] = 1.jpg

        FILE *file;
        unsigned char *buffer;
        unsigned long fileLen;

        //Open file
        file = fopen(argv[1], "rb");
        if (!file)
        {
                fprintf(stderr, "Unable to open file %s", argv[1]);
                return;
        }

        //Get file length
        fseek(file, 0, SEEK_END);
        fileLen=ftell(file);
        fseek(file, 0, SEEK_SET);

        //Allocate memory
        buffer=(char *)malloc(fileLen);
        if (!buffer)
        {
                fprintf(stderr, "Memory error!");
                                fclose(file);
                return 1;
        }
        //printf("\n3. Current position is %d\n",ftell(file));  -- will tell u the location
       fread(buffer,fileLen,sizeof(unsigned char),file);
       fclose(file);

       int i=0;

       while (i < fileLen){
           printf("%02X ",((unsigned char)buffer[i]);
           i++;
           if( ! (i % 16) ) printf( "\n" );
       }

        return 0;
}
