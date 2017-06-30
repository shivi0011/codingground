#include <stdio.h>
#include <dirent.h>
 
int main(void)
{
   FILE *fp1,*fp2;
   fp1 = fopen("circle.png","rb");
   if(fp1==NULL) printf("Error in opening the file!!\n");
   else
   {
       fp2 = fopen("newTest.png","wb");
       
       size_t n, m;                       // size_t == unsigned long int
       unsigned char buff[8192];
        do 
        {
            n = fread(buff, 1, sizeof buff, fp1);
            if (n) m = fwrite(buff, 1, n, fp2);
            else   m = 0;
        } while ((n > 0) && (n == m));
        if (m) perror("copy");
       
       fclose(fp1);
       fclose(fp2);
   }
    return 0;
}

:::::::::::::::::::: OR ::::::::::::::::::::::::::::::
Its more space efficient as we're allocating only exact required space.

#include <stdio.h>
#include <dirent.h>
#include<stdlib.h>

int main(void)
{
   FILE *fp1,*fp2;
   char ch;
   unsigned int fileLen;
   unsigned char *buff;
   fp1 = fopen("circle.png","rb");
   if(fp1==NULL) printf("Error in opening the file!!\n");
   else
   {
       fseek(fp1,0,SEEK_END);
       fileLen = ftell(fp1);
       fseek(fp1,0,SEEK_SET);
        
        buff = (char *)malloc(sizeof(char)*fileLen);   
        if(buff==NULL)printf("Error in malloc");
       
        fp2 = fopen("newTest.png","wb");
       
        //printf("%d",fileLen);
        unsigned int i=0,n,m;
        
        while(i<fileLen)
        {
            n = fread(buff,1,sizeof(buff),fp1);       //or    n = fread(buff,1,1,fp1);
            if(n) m = fwrite(buff,1,n,fp2);           //or    if(n) m = fwrite(buff,1,1,fp2);
            
            i++;  
        }
        
       fclose(fp1);
       fclose(fp2);
   }
    return 0;
}
