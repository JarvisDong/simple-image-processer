#include <image.h>

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
	pixel = img.pixel; //TODO:something extremely wrong here 
}

void ResetSize(int w, int h, Pixel *pixel) {
	if (pixel != NULL) {pixel = new Pixel[w*h];}
	else {width = 0;height = 0;}
}