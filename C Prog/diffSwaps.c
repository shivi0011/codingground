#include <stdio.h>

void swapWithArith(int *a, int *b)
{
    *a = *a+*b;
    *b = *a-*b;
    *a = *a-*b;
}

void swapWithXor(int *a,int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void swapWithDiv(int *a,int *b)
{
    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b; 
    
}

void swapWithOneLiner(int *a,int *b)
{
    *b = (*a + *b)-(*a = *b);
}

int main()
{
    int a=2,b=3;
    printf("%d %d\n",a,b);
    
    swapWithArith(&a,&b);
    printf("%d %d\n",a,b);
    
    swapWithXor(&a,&b);
    printf("%d %d\n",a,b);
    
    swapWithDiv(&a,&b);
    printf("%d %d\n",a,b);
    
    swapWithOneLiner(&a,&b);
    printf("%d %d\n",a,b);
    return 0;
}

