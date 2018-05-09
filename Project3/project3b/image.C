#include <image.h>
#define NULL __null

//default constructor
Image::Image(void) {
	width = 0;
	height = 0;
	pixel = NULL;
}

//parameterized constructor
Image::Image(int w, int h, Pixel *pixel) {
	width = w;
	height = h;
	pixel = new Pixel[w*h];
}

//copy constructor
Image::Image(Image &img) {
	width = img.width;
	height = img.height;
	//TODO: pixel = img.pixel;
}

void
Image::ResetSize(int w, int h) {
	// for combine blend and half functions 
	if (pixel == NULL) {
		width = w;
		height = h;
		pixel = new Pixel[w*h];
	}
	//TODO: else:for further usage
}