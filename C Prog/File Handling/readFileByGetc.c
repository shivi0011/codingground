#include <stdio.h>

int main()
{
    FILE *fp;
    
    fp = fopen("test.txt","r");
    int c;
    if(fp==NULL)
    printf("File not opened successfully!!\n");
    else
    {
        char ch = getc(fp);
        while(ch!=EOF)
        {
            putchar(ch);
            ch = getc(fp);
        }
    }
    
    /*check errors*/
    if(feof(fp))                    //feof is used to check the end of file
    printf("Reached end of file\n");
    else
    printf("Some error occured!");
    
    fclose(fp);
    return 0;
    
}

