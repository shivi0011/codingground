/*
How do we store a number in the array, and why do we store it the way we do?

If after reading this tutorial you look at some of the accepted solutions in C/C++ for this problem, you will see that contestants actually stored the numbers "backwards", for example:

123 would be saved in an array, say a, as:

a = [3,2,1];

This is done such that when the digit by digit calculations are being performed, the "carry" can be placed on the positions of the array with higher index. This way, we are sure that carry is computed and placed correctly on the array.

Also, computing the products this way and maintaining the variable, m, allows us to print the result directly, by looping from a[m-1] until a[0].
*/

#include<stdio.h>
int main()
{
    int t;
    int a[200]; //array will have the capacity to store 200 digits.
    int n,i,j,temp,m,x;

    scanf("%d",&t);  //test cases
    while(t--)
    {
       scanf("%d",&n);
       a[0]=1;  //initializes array with only 1 digit, the digit 1.
       m=1;    // initializes digit counter

       temp = 0; //Initializes carry variable to 0.
       for(i=1;i<=n;i++)
       {
            for(j=0;j<m;j++)
            {
               x = a[j]*i+temp; //x contains the digit by digit product
               a[j]=x%10; //Contains the digit to store in position j
               temp = x/10; //Contains the carry value that will be stored on later indexes
            }
             while(temp>0) //while loop that will store the carry value on array.
             { 
               a[m]=temp%10;
               temp = temp/10;
               m++; // increments digit counter
             }
      }
              for(i=m-1;i>=0;i--) //printing answer
              printf("%d",a[i]);
              printf("\n");
    }
    return 0;
}
