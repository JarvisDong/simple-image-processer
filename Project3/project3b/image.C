#include <image.h>
struct Pixel {
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

struct Image {
	int width;
	int height;
	Pixel *pixel;
	
	//default constructor
	Image(void) {
		width = 0; height = 0;
		pixel = (Pixel *) malloc(width*height*sizeof(Pixel));
	}
	//parameterized constructor
	Image(int w, int h, Pixel *pixel) {
		width = w; height = h;
		pixel = (Pixel *) malloc(w*h*sizeof(Pixel));
	}
	//copy constructor
	Image(Image &);
	//size will need to be reset when putting a valid image in it.
	void ResetSize(int width, int height) {width=0; height=0};
};
