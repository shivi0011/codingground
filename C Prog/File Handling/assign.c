#include <stdio.h>
#include <string.h>

#define R 10      //Rows or lines
#define L 128     //max length of one line 

int main()
{
   char line[R][L];
   int count=0,totLines,i=0;
   FILE *fp;
   fp = fopen("test.txt","r");
   if(fp==NULL)printf("Error in opening file!!\n");
   else
   {
       char word[50];
       printf("Enter word to search : ");
       scanf("%s",word);
       int found=0,wlen = strlen(word);
       
       while(fgets(line[i],L,fp)) //this line is copying the content line by line pointed to by fp to line array
       {
           int j,k=0,len = strlen(line[i]);
           line[i][len - 1] = '\0';   //and at last we need to append the NULL
           
           for(j=0;j<len;j++)
           {
               for(k=0;word[k]!='\0';k++)
               {
                   if(line[i][j]!=word[k]) break;
                   
                   else //ie. char matched
                   {
                        j++;    //then need to increment both
                        if(word[k+1]=='\0')
                        {
                            printf("word \"%s\" found at %d position in %d line of file\n",word,j-wlen+1,i+1);
                            found=1;
                            count++;
                        }
                   }
               }
           }
           i++;         //to count number of lines in file so that we can use for printing
       }
       printf("Total %d counts are found for \"%s\"\n",count,word);
       if(found==0)
       printf("word \"%s\" not found!!\n",word);
       totLines = i;
       
       /* to print the lines of file
       for(i=0;i<totLines;i++)
       printf("%s\n",line[i]);
       */
       fclose(fp);
   }
    return 0;
}
