#include <stdio.h>
#include <dirent.h>
 
int main(void)
{
   FILE *fp1,*fp2;
   char ch;
   fp1 = fopen("test.txt","r");
   if(fp1==NULL) printf("Error in opening the file!!\n");
   else
   {
       fp2 = fopen("newTest.txt","w");
       for(ch=fgetc(fp1);ch!=EOF;ch=fgetc(fp1))
        {
             fputc(ch,fp2);
        }
       for(ch=fgetc(fp2);ch!=EOF;ch=fgetc(fp2))
        {
             //printf("%c",ch);
             putchar(ch);
        }
       
       fclose(fp1);
       fclose(fp2);
   }
    return 0;
}
