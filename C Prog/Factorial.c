    #include<stdio.h>
    #include<stdlib.h>
    void findfact(int n)
    {
    int i,value=1;

    for(i=n;i>0;i--)
    value *= i;

    printf("Factorial of %d is %d\n",n,value);

    }

    int main()
    {
    int n=5;
    printf("Enter value of n : \n");

    scanf("%d",&n);
    findfact(n);
    return 0;
    }
