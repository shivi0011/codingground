#include <stdio.h>

int main()
{
   FILE *fp;
   fp = fopen("test.txt","w");
   if(fp==NULL)printf("Error in opening file!!\n");
   else
   {
       int i,lines;
       char buff[1000];
       printf("Enter how many lines u want to enter : ");
       scanf("%d",&lines);
       for(i=0;i<lines;i++)
       {
       fgets(buff,1000,stdin);      //from stdin ie. from standard input copy content to buffer
       fputs(buff,fp);      //it will put the content of buffer to the file
       //fprintf(fp,buff);    //here both fputs and fprintf r same as we dont need any formatting
                            //for formatting we can use fprintf
       }
       fclose(fp);
   }
   
    return 0;
}

