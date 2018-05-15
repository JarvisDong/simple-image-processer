#ifndef PIXEL_H
#define PIXEL_H

struct Pixel{
	unsigned char r, g, b;
};

#endif

#ifndef IMAGE_H
#define IMAGE_H

class Image {
public:
	Image(void);
	Image(int width, int height, Pixel *pixel);
	Image(Image &);
	~Image();

private:
	int width;
	int height;
	Pixel *pixel;
	
public:
	void ResetSize(int w, int h);
	//getter
	int getWidth();
	int getHeight();
	Pixel* getPixel();
	//setter
	void setWidth(int w);
	void setHeight(int h);
	void setPixel(Pixel *px);
};


#endif
