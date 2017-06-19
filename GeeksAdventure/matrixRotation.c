#include <stdio.h>
#include<stdlib.h>

void rotateMatrixBy90(int *A[3],int *B[3],int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            A[i][j] = A[i][j] ;
        }
    }
}



int main(void)
{
    int i,j,m=3,n=3;
    int *A[m],*B[m];
    
    for(i=0;i<3;i++)
    {
        A[i] = (int *)malloc(sizeof(int)*n);
        B[i] = (int *)malloc(sizeof(int)*n);
    }
    printf("Enter values for matrix A: \n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("A[%d][%d]: ",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    printf("Enter values for matrix B: \n");
    
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("B[%d][%d] : ",i,j);
            scanf("%d",&B[i][j]);
        }
    }
    
    printf(":::::Matrix A:::::::\n");
        for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    
    printf(":::::Matrix B:::::::\n");
        for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    
    rotateMatrixBy90(A,B,m,n);
    printf(":::::Matrix after Rotation:::::::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",B[i][j]);
        }
        printf("\n");
    }
    return 0;
}
