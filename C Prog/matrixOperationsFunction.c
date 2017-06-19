#include <stdio.h>
#include<stdlib.h>

void matrixAddition(int *A[3],int *B[3], int *C[3],int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void matrixSubtraction(int *A[3],int *B[3], int *D[3],int m, int n)
{
    int i,j;
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                D[i][j] = A[i][j] - B[i][j];
            }
        }
}

void matrixMul(int *A[3],int *B[3], int *E[3],int m, int n)
{
    int i,j,k;
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                E[i][j]=0;              //my mistake
                 for(k=0;k<m;k++)
                 E[i][j] += A[i][k]*B[k][j];
            }
        }
}        

void matrixTranspose(int *A[3],int *F[3], int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            F[i][j] = A[j][i];    
        }
    }
    
    
    
}

int main(void)
{
    int i,j,m=3,n=3;
    //int A[m][n],B[m][n];
    int *A[m],*B[m],*C[m],*D[m],*E[m], *F[m];
    
    for(i=0;i<3;i++)
    {
        A[i] = (int *)malloc(sizeof(int)*n);
        B[i] = (int *)malloc(sizeof(int)*n);
        C[i] = (int *)malloc(sizeof(int)*n);
        D[i] = (int *)malloc(sizeof(int)*n);
        E[i] = (int *)malloc(sizeof(int)*n);
        F[i] = (int *)malloc(sizeof(int)*n);
        
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
    printf("Enter values for matrix A: \n");
    
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
    
    //int C[m][n];
    /*Matrix Addition*/
    matrixAddition(A,B,C,m,n);
    printf(":::::Addition Matrix C:::::::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",C[i][j]);
        }
        printf("\n");
    }
    
    //int D[m][n];
    /*Matrix Subtraction*/
    matrixSubtraction(A,B,D,m,n);
    printf(":::::Subtraction Matrix D:::::::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",D[i][j]);
        }
        printf("\n");
    }

    //int E[m][n];
    /*Matrix Multiplication*/
    matrixMul(A,B,E,m,n);
    printf(":::::Multiplication Matrix:::::::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",E[i][j]);
        }
        printf("\n");
    }

    matrixTranspose(A,F,m,n);
    printf(":::::Transpose of Matrix:::::::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",F[i][j]);
        }
        printf("\n");
    }
    return 0;
}
