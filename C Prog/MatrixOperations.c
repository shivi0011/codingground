#include <stdio.h>
#include<stdlib.h>

int main(void)
{
    int i,j,m=3,n=3;
    //int A[m][n],B[m][n];
    int *A[3],*B[3],*C[3],*D[3],*E[3];
    
    for(i=0;i<3;i++)
    {
        A[i] = (int *)malloc(sizeof(int)*3);
        B[i] = (int *)malloc(sizeof(int)*3);
        C[i] = (int *)malloc(sizeof(int)*3);
        D[i] = (int *)malloc(sizeof(int)*3);
        E[i] = (int *)malloc(sizeof(int)*3);
        
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
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
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
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            D[i][j] = A[i][j] - B[i][j];
        }
    }
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
    int k;
    /*Matrix Multiplication*/
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                E[i][j]=0;              //my mistake
                 for(k=0;k<m;k++)
                 E[i][j] += A[i][k]*B[k][j];
            }
        }
    printf(":::::Multiplication Matrix:::::::\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",E[i][j]);
        }
        printf("\n");
    }

    return 0;
}
