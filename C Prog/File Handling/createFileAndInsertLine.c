#include <stdio.h>

int main()
{
   FILE *fp;
   fp = fopen("test.txt","w");
   if(fp==NULL)printf("Error in opening file!!\n");
   else
   {
       char buff[1000];
       printf("Enter some text : ");
       fgets(buff,1000,stdin);    //use stdin in place of fp
       //fscanf(stdin,"%s",buff);   //will take just first word         
       fprintf(fp,buff);
       fclose(fp);
   }
   
    return 0;
}

