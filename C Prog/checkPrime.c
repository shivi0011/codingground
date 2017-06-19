#include <stdio.h>
#include<stdlib.h>
#include<math.h>

int checkPrime(int n)
{
    int i, sqrtn;
    sqrtn = sqrt(n);
    
    if(n<=1) return 0;
    if(n==2) return 1;
    if(n%2==0) return 0;
    for(i=3;i<sqrtn;i+=2)
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main(void)
{
int n;
printf("Enter any number : ");
scanf("%d",&n);

if(checkPrime(n))
printf("%d is a prime number!\n",n);
else
printf("%d is not a prime number!!\n",n);


    return 0;
}
