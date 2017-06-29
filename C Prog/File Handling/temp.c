

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
