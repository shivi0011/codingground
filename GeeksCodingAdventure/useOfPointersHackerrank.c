#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int* getRecord(int s_size, int* s, int *result_size)
{
    int i;
    int max=s[0],min=s[0],highc=0,lowc=0;
    
    for(i=0;i<s_size;i++)
    {
        //printf("max=%d min=%d\n",max,min);
        if(s[i]>=max)
        { 
            if(s[i]>max)
                highc++;
            
            max=s[i];
        }
        if(s[i]<=min)  
        {
            if(s[i]<min)
            {
                //printf(" >>%d<< ",s[i]);
                lowc++;
            }
               
            min = s[i];
            
        }
    }
    //printf("\n%d %d\n",highc,lowc);
    *result_size = 2;          //mind it to put *
    //int res[] = {highc,lowc};     we cant return like this..as this is local var  
    //static int res[] = {highc,lowc};      this is also wrong as in case of multiple calls it wont work
    int *res = (int*)malloc(sizeof(int)*2);     //this is correct way of returning 2 things to main
    res[0] = highc;
    res[1] = lowc;
return res;
}

int main() {
    int n; 
    scanf("%d",&n);
    int *s = malloc(sizeof(int) * n);
    for(int s_i = 0; s_i < n; s_i++){
       scanf("%d",&s[s_i]);
    }
    int result_size;
    int* result = getRecord(n, s, &result_size);
    for(int i = 0; i < result_size; i++) {
        if (i) 
        {
            printf(" ");
        }
        printf("%d", result[i]);
    }
    puts("");
    return 0;
}
