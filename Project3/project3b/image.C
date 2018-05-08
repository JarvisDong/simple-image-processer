#include <image.h>

//default constructor
Image::Image(void) {
	width = 0;
	height = 0;
	pixel = new Pixel[width*height];
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
	pixel = img.pixel;
}

void ResetSize(int width, int height) {
	width = 0;
	height = 0;
}