#include <iostream>
using namespace std;

/* Function to reverse bits of num */
unsigned int reverseBits(unsigned int num)
{
    unsigned int  NO_OF_BITS = sizeof(num) * 8;
    unsigned int reverse_num = 0, i, temp;
 
    for (i = 0; i < NO_OF_BITS; i++)
    {
        temp = (num & (1 << i));
        if(temp)
            reverse_num |= (1 << ((NO_OF_BITS - 1) - i));
    }
  
    return reverse_num;
}
 
/* Driver function to test above function */
int mainss()
{
  /*  unsigned int x = 2; 
    printf("%u", reverseBits(2));
    getchar();*/

	
        int res         = 0;          //Result
 
       int temp = 0xff - 2;  
	   return 0;
}