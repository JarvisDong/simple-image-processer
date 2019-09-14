#include <image.h>
#include <source.h>
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
Image::~Image() {if (pixel != NULL) {delete [] pixel; pixel = NULL; }}

int Image::getWidth() const {return width;}

int Image::getHeight() const {return height;}

Pixel *Image::getPixel() const {return pixel;}

void Image::setWidth(int w) {width = w;}

void Image::setHeight(int h) {height = h;};

void Image::setSource(Source *src){source = src;}

void
Image::setPixel(Pixel *px) {
	for (int i=0; i<width; i++) {
		for (int j=0; j<height; j++) {
			pixel[j*width+i] = px[j*width+i];
		}
	}
}

void
Image::ResetSize(int w, int h) {
	// for combine blend and half functions 
	if (pixel != NULL) {
		delete [] pixel;
	}

	width = w;
	height = h;
	pixel = new Pixel[w*h];
}

void Image::Update(void) const {
	if (source != NULL) {
		source -> Update();
	}
}