#ifndef PIXEL_H
#define PIXEL_H

struct Pixel{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

#endif

#ifndef IMAGE_H
#define IMAGE_H

struct Image {
	int width;
	int height;
	Pixel *pixel;
		Image(void);
		Image(int width, int height, Pixel *pixel);
		Image(Image &);
	void ResetSize(int w, int h);
};
#endif
