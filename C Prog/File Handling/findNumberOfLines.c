#include <stdio.h>
#include<string.h>

#define R 10
#define L 128

int main()
{
   int lineCount=0;
   FILE *fp;
   fp = fopen("test.txt","r");
   if(fp==NULL)printf("Error in opening file!!\n");
   else
   {
       char ch = fgetc(fp);
       while(ch!=EOF)
       {
           if(ch=='\n')
               lineCount++;
               
           ch = fgetc(fp);
       }
       
       /*
       OR equivalent for loop
       for(ch=fgetc(fp);ch!=EOF;ch=fgetc(fp))
       {
          if(ch=='\n')
              lineCount++;
       }
       
       */
       
       printf("Total number of lines are : %d\n",lineCount);
       fclose(fp);
   }
   
    return 0;
}

