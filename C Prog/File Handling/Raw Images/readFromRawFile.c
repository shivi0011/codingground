//numbers.raw file is having the numbers in it
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *ptrRAWread;

        union twobytes 
        {
        int intvalue;
        char byte [sizeof (int)];
         } bytes;
        
        char *buffer;
        
        ptrRAWread = fopen ("numbers.raw", "rb");
        
        fseek (ptrRAWread, 0, SEEK_END); 
        int lSize = ftell (ptrRAWread);
        rewind (ptrRAWread);
        
        buffer = (char*) malloc (sizeof (char) * (lSize));
        if (buffer == NULL) {fputs ("\nMemoryerror\n", stderr); exit(2);}
        
        int result = fread (buffer, 1, lSize, ptrRAWread);
        if (result != lSize) {fputs ("\nReadingerror\n", stderr); exit(3);}
        
        bytes.byte[0] = buffer[0];
        bytes.byte[1] = buffer[1];
        bytes.byte[2] = 0;
        bytes.byte[3] = 0;
        
        printf ("\nbytes.intvalue: %i\n", bytes.intvalue);
            

    return 0;
}

