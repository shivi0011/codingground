#include <stdio.h>
#include<string.h>

#define R 10      //Rows or lines
#define L 128     //max length of one line 

int main()
{
   char line[R][L];
   int totLines,i=0;
   FILE *fp;
   fp = fopen("test.txt","r");
   if(fp==NULL)printf("Error in opening file!!\n");
   else
   {
       while(fgets(line[i],L,fp))     //this line copying the content pointed by fp to line array
       {
           line[i][strlen(line[i]) - 1] = '\0';   //and at last we need to append the NULL
           i++;                                   //to count number of lines in file so that we can use for printing
       }
       totLines = i;
       
       for(i=0;i<totLines;i++)
       printf("%s\n",line[i]);
       
       fclose(fp);
   }
    return 0;
}

