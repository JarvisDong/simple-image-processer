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
	pixel = new Pixel[width*height];
	for (int i=0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			pixel[j*width+i] = img.pixel[j*width+i];
		}
	}
}

//destructor
Image::~Image() {
	delete [] pixel;
}

int getWidth() {
	return width;
}

int getHeight() {
	return height;
}

Pixel getPixel() {
	return pixel;
}

void setWidth(int w) {
	width = w;
}

void setHeight(int h) {
	height = h;
};

void setPixel(Pixel *px) {
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			pixel[j*width+i] = px[j*width+i];
		}
	}
}


void
Image::ResetSize(int w, int h) {
	// for combine blend and half functions 
	if (pixel == NULL) {
		width = w;
		height = h;
		pixel = new Pixel[w*h];
	}
}