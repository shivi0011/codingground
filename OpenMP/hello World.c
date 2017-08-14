/*compile with -fopenmp switch*/
#include <stdio.h>
#include<omp.h>

int main()
{
    omp_set_num_threads(4);
    #pragma omp parallel
    {
        printf("%d\n",omp_get_thread_num());
    printf("Hello, World!\n");
    }
    return 0;
}

