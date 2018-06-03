#include <sink.h>
#include <image.h>
#include <logging.h>
#define NULL __null

Sink::Sink(void) {
    sink_image = NULL;
    sink_image2 = NULL;
}

void
Sink::SetInput(const Image *img) {
    sink_image = img;
}

void
Sink::SetInput2(const Image *img) {
    sink_image2 = img;
}

void
CheckSum::OutputCheckSum(const char *filename) {
    FILE *f = fopen(filename, "w");
    unsigned char red = 0;
    unsigned char green = 0;
    unsigned char blue = 0;
    int sink_image_width  = sink_image->getWidth();
    int sink_image_height  = sink_image->getHeight();
    Pixel * sink_iamge_pixel = sink_image->getPixel();
    for(int c = 0; c < sink_image_width; c++) {
		for(int r = 0; r < sink_image_height; r++) {
            int index = r*sink_image_width + c;
            red += sink_iamge_pixel[index].r;
            green += sink_iamge_pixel[index].g;
            blue += sink_iamge_pixel[index].b;
        }
    }
    fprintf(f, "CHECKSUM: %d, %d, %d\n", red, green, blue);
    fclose(f);
}