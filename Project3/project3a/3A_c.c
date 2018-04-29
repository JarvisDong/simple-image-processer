#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef struct
{
	Pixel *pixel;
	int width;
	int height;

} Image;

Image *
ReadImage(char *filename)
{
	char magicNum[128];
	int width, height, maxval;

	Image *image = (Image *) malloc(sizeof(Image)); //need a free()
	FILE *f_in = fopen(filename, "r");
 	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval); //magicNum = "P6", width = 1786, height = 1344, maxval = 255
 	image->width = width;
 	image->height = height;
 	image->pixel = (Pixel *) malloc(width*height*sizeof(Pixel)); //need a free()
 	fclose(f_in);
 	return image;
}


void WriteImage(Image *img, char *filename)
{
	FILE *f_out = fopen(filename, "w");
	fprintf(f_out, "P6\n%d %d\n%d\n", img->width, img->height, 255);
	fclose(f_out);
}

Image *
YellowDiagonal(Image *input)
{	
	for (int i=0; i<input->width; i++) {
		for (int j=0; j<input->height; j++) {
			if (i==j) {
				input->pixel[j*input->width+i].r = 255;
				input->pixel[j*input->width+i].g = 255;
				input->pixel[j*input->width+i].b = 0;
			}
		}
	}
}

void freePixelofImage() {

}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */
	Image *input = ReadImage(argv[1]);
	Image *output = YellowDiagonal(input);
	WriteImage(output, argv[2]);
	return 0;
}
