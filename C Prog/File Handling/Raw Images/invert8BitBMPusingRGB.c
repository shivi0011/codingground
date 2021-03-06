#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
/*-------STRUCTURES---------*/
typedef struct {int rows; int cols; int bits; unsigned char* data;} sImage;
 
/*-------PROTOTYPES---------*/
long getImageInfo(FILE*, long, int);
void copyImageInfo(FILE*, FILE*);
void copyColorTable(FILE*, FILE*, int);
 
int main()
{
  FILE         *bmpInput, *bmpOutput;
  sImage      originalImage;
  unsigned char      someChar;
  unsigned char*   pChar;
  int         nColors;  /* BMP number of colors */
  long         fileSize; /* BMP file size */
  int         vectorSize; /* BMP vector size */
  int         r, c;       /* r = rows, c = cols */
  int           pixels[600][600];
  char imagein[30];
  char imageout[30];
  /* initialize pointer */
  someChar = '0';
  pChar = &someChar;
  printf("Enter input image : ");
  gets(imagein);
  
  printf("Enter output image : ");
  gets(imageout);
  
  /*--------READ INPUT FILE------------*/
  bmpInput = fopen(imagein, "rb");
  fseek(bmpInput, 0L, SEEK_END);
  
  /*--------DECLARE OUTPUT FILE--------*/
  bmpOutput = fopen(imageout, "wb");
 
  /*--------GET BMP DATA---------------*/
  originalImage.cols = (int)getImageInfo(bmpInput, 18, 4);  //2nd is offset... 3rd is no. of chars
  originalImage.rows = (int)getImageInfo(bmpInput, 22, 4);
  originalImage.bits = (int)getImageInfo(bmpInput, 28, 4);
  fileSize = getImageInfo(bmpInput, 2, 4);
  nColors = getImageInfo(bmpInput, 46, 4);
  vectorSize = fileSize - (14 + 40 + 4*nColors);
 
  /*-------PRINT DATA TO SCREEN-------------*/
  printf("Width: %d\n", originalImage.cols);
  printf("Height: %d\n", originalImage.rows);
  printf("Bits per Pixel: %d\n", originalImage.bits);
  printf("File size: %ld\n", fileSize);
  printf("# Colors: %d\n", nColors);
  printf("Vector size: %d\n", vectorSize);
  
  copyImageInfo(bmpInput, bmpOutput);
  copyColorTable(bmpInput, bmpOutput, nColors);
 
  /*----START AT BEGINNING OF RASTER DATA-----*/
  fseek(bmpInput, (54 + 4*nColors), SEEK_SET);      //BMP header size is 54 Byte
 
  /*----------READ RASTER DATA----------*/
  for(r=0; r<=originalImage.rows - 1; r++)
  {
    for(c=0; c<=originalImage.cols - 1; c++)
    {
      /*-----read data, reflect and write to output file----*/
      fread(pChar, sizeof(char), 1, bmpInput);
      pixels[r][c] = *pChar;
      *pChar = 255 - *pChar;
      fwrite(pChar, sizeof(char), 1, bmpOutput);
    }
  }
  
  fclose(bmpInput);
  fclose(bmpOutput);
  return 0;
}
 
/*----------GET IMAGE INFO SUBPROGRAM--------------*/
long getImageInfo(FILE* inputFile, long offset, int numberOfChars)
{
  unsigned char     ptrC;
  long          value = 0L;
  int           i;

  fseek(inputFile, offset, SEEK_SET);   //offset is used to shift the file pointer to that location

  for(i=0; i<numberOfChars; i++)  
  {
    fread(&ptrC, 1, 1, inputFile); // sizeof(char) is always 1, no need to use it
    value = value + ((long)ptrC << 8*i); // Shifts are a lot simpler to look at and understand what's the meaning
  }
  return value; 
}
 
 
 
 
/*-------------COPIES HEADER AND INFO HEADER----------------*/
void copyImageInfo(FILE* inputFile, FILE* outputFile)
{
  unsigned char      *ptrC;
  unsigned char      dummy;
  int i;
  dummy = '0';
  ptrC = &dummy;
 
  fseek(inputFile, 0L, SEEK_SET);
  fseek(outputFile, 0L, SEEK_SET);
 
  for(i=0; i<=50; i++)
  {
    fread(ptrC, sizeof(char), 1, inputFile);
    fwrite(ptrC, sizeof(char), 1, outputFile);
  }
}
 
/*----------------COPIES COLOR TABLE-----------------------------*/
void copyColorTable(FILE* inputFile, FILE* outputFile, int nColors)
{
  unsigned char      *ptrC;
  unsigned char      dummy;
  int i;
 
  dummy = '0';
  ptrC = &dummy;
 
  fseek(inputFile, 54L, SEEK_SET);
  fseek(outputFile, 54L, SEEK_SET);
 
  for(i=0; i<=(4*nColors); i++)  /* there are (4*nColors) bytesin color table */
  {
    fread(ptrC, sizeof(char), 1, inputFile);
    fwrite(ptrC, sizeof(char), 1, outputFile);
  }
 
}
