#include <stdio.h>

int main()
{
    FILE *fp;
    int ccount=0,wc=0;
    fp = fopen("test.txt","r");
    if(fp==NULL)printf("Error in opening file!\n");
    else
    {
        char ch = fgetc(fp);
        while(ch!=EOF)
        {
            if(ch==' ' || ch=='\n') wc++;
            else ccount++;
        
            ch = fgetc(fp);         //mistake... u need to again take the next char..or just use for version
        }                           // for(ch=fgetc(fp);ch!=EOF;ch=fgetc(fp))
    }
    printf("Character count = %d\n",ccount);
    printf("Word count = %d\n",wc);
    return 0;
}

