#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef struct {
	Pixel *pixel;
	int width;
	int height;

} Image;

Image *ReadImage(char *filename) {
	char magicNum[128];
	int width, height, maxval;

	FILE *f_in;
	f_in = fopen(filename, "r");
 	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &width, &height, &maxval); //magicNum = "P6", width = 1786, height = 1344, maxval = 255
 	Image *image = (Image *) malloc(sizeof(Image));
 	image->width = width;
 	image->height = height;
 	image->pixel = (Pixel *) malloc(width*height*sizeof(Pixel));
 	fread(image->pixel, sizeof(Pixel), height*width, f_in);
 	fclose(f_in);
 	return image;
}


void WriteImage(Image *img, char *filename)
{
	FILE *f_out;
	f_out = fopen(filename, "w");
	fprintf(f_out, "P6\n%d %d\n%d\n", img->width, img->height, 255);
	fwrite(img->pixel, sizeof(Pixel), img->height*img->width, f_out);
	fclose(f_out);
}

Image *YellowDiagonal(Image *input) {	
	int w, h;
	w = input->width;
	h = input->height;

	//make a copy of original image
	Image *copy = (Image *) malloc(sizeof(Image));
	copy->width = w;
	copy->height = h;
	copy->pixel = (Pixel *) malloc(w*h*sizeof(Pixel));

	for (int i=0; i<w; i++) {
		for (int j=0; j<h; j++) {
			if (i==j) {
				(copy->pixel)[j*w+i].r = 255;
				(copy->pixel)[j*w+i].g = 255;
				(copy->pixel)[j*w+i].b = 0;
			}
		}
	}

	return copy;
}

void freePixelandImage(Image *img) {
	free(img->pixel);
	free(img);
}

int main(int argc, char *argv[])
{
   /* Read an image, apply yellow diagonal to it, then write */
	Image *input, *output;
	input = ReadImage(argv[1]);
	output = YellowDiagonal(input);
	WriteImage(output, argv[2]);
	freePixelandImage(input);
	freePixelandImage(output);
	return 0;
}
