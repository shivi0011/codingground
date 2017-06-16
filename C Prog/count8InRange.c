#include<stdio.h>

int count8(int from, int to) 
{
    int i, count = 0;
    for (i = from; i <= to; i++) {
        int j = i;
        while (j > 0) {
            if (j % 10 == 8)
                count++;
            j /= 10;
        }
    }
    return count;
}

int main()
{
    printf("%d\n",count8(1,100));
    return 0;
    
}
