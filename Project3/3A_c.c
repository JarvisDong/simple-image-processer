#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
/* data members go here */
} Image;

Image *
ReadImage(char *filename)
{
/* These lines are useful:
 * char magicNum[128];
 * int width, height, maxval;
 * fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval);  
 * where f_in is the name of the input FILE.
 */
}


void WriteImage(Image *img, char *filename)
{
}

Image *
YellowDiagonal(Image *input)
{
}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */
}
