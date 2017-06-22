#include <stdio.h>
#include<stdlib.h>

void matrixAddition(int **A,int **B, int **C,int m, int n)
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

void matrixSubtraction(int **A,int **B, int **D,int m, int n)
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

void matrixMul(int **A,int **B, int **E,int m, int n)
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

void matrixTranspose(int **A,int **F, int m,int n)
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
    int i,j,m,n;
    printf("Enter row index : ");
    scanf("%d",&m);
    printf("Enter col index : ");
    scanf("%d",&n);
    int **A,**B,**C,**D,**E,**F;
    A = (int **)malloc(sizeof(int *)*n);
    B = (int **)malloc(sizeof(int *)*n);
    C = (int **)malloc(sizeof(int *)*n);
    D = (int **)malloc(sizeof(int *)*n);
    E = (int **)malloc(sizeof(int *)*n);
    F = (int **)malloc(sizeof(int *)*n);
    
    for(i=0;i<m;i++)
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
