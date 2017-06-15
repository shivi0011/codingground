#include <stdio.h>

int fact(int n)
{
    if(n==0 || n==1)
    return 1;
    
    return n*fact(n-1);
}

int findnCr(int n,int r)
{
    int i;
    return fact(n)/(fact(n-r)*fact(r));
    
}

int main()
{
    int n,r;
    printf("Enter value of n and r :");
    scanf("%d %d",&n,&r);
    printf("Value of nCr is %d\n",findnCr(n,r));
    return 0;
}
