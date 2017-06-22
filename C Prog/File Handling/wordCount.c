#include <stdio.h>
#include <string.h>

#define L 128     //max length of one line 

int main()
{
   char line[L];
   int wc=0,i=0;
   FILE *fp;
   fp = fopen("test.txt","r");
   if(fp==NULL)printf("Error in opening file!!\n");
   else
   {
       while(fgets(line,L,fp)) //this line is copying the content line by line pointed to by fp to line array
       {
           int j,flag=0,len=strlen(line);
           line[len - 1] = '\0';   //and at last we need to append the NULL
           //printf(">>%s<<\n",line);
           printf("\nCurrent length = %d\n",len);
           for(j=0;j<len;j++)
           {
               while((line[j]!=' ' && line[j]!='\t') && j<len)
               {
                   printf("%c",line[j]);
                   //printf("\nj=%d\n",j);
                   
                   if(line[j+1]==' ' || line[j+1]=='\t')
                   {printf("<<");wc++;}
                   
                   
                   j++;
               }
              
           }
       }       
        printf("\nTotal word count is %d\n",wc);
       fclose(fp);
   }
    return 0;
}
