#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
   int a;
   char b[6];
   
   printf("Enter any number to check palindrome : ");
   scanf("%d",&a);
   
   /*Int to String conversion*/
   sprintf(b,"%d",a);
   //printf("%s",b);
   int len = strlen(b);
   int i,start = 0,flag=0;
   int end = len-1;
   while(start<end)
   {
       if(b[start]!=b[end])
       flag=1;
       start++;end--;
   }
   if(flag==1)
   printf("not palindrome\n");
   else
   printf("Palindrome\n");
   return 0;
}
