#include <source.h>
#include <image.h>
#include <logging.h>

Source::Source() {
    source_image.setSource(this);
}

Image*
Source::GetOutput() {return &source_image;};


Color::Color(void) {
    width = 0;
    height = 0;
    red = 0;
    green = 0;
    blue = 0;
}

Color::Color(int w, int h, unsigned char r, unsigned char g, unsigned char b) {
    width = w;
    height = h;
    red = r;
    green = g;
    blue = b;
}

void
Color::Execute(void) {
	source_image.ResetSize(width, height);
	int source_image_width = source_image.getWidth();
	int source_image_height = source_image.getHeight();
	Pixel *source_image_pixel = source_image.getPixel();

    for(int c = 0; c < source_image_width; c++) {
		for(int r = 0; r < source_image_height; r++) {
            int index = r*source_image_width + c;
            source_image_pixel[index].r = red;
            source_image_pixel[index].g = green;
            source_image_pixel[index].b = blue;
        }
    }
}

void
Color::Update(){ Execute(); }

