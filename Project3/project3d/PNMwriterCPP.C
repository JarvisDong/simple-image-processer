#include <PNMwriterCPP.h>
#include <string.h>
#include <image.h>
#include <fstream>
#include <iostream>

using namespace std;

PNMwriter::PNMwriter(void) {;}

void
PNMwriter::Write(char *filename) {
    int sink_image_width = sink_image->getWidth();
    int sink_image_height = sink_image->getHeight();
    Pixel *sink_image_pixel = sink_image->getPixel();

    ofstream f_out;
    f_out.open(filename);
    f_out << "P6" << endl;
    f_out << sink_image_width << " " << sink_image_height << endl;
    f_out << 255 << endl;

	for (int i = 0; i < sink_image_width*sink_image_height; i++) {
		f_out << sink_image_pixel[i].r << noskipws << sink_image_pixel[i].g << sink_image_pixel[i].b;
	}
	f_out.close();

    // FILE *f_out = fopen(filename, "w");
	// fprintf(f_out, "P6\n%d %d\n%d\n", sink_image_width, sink_image_height, 255);
	// fwrite(sink_image_pixel, sizeof(Pixel), sink_image_width * sink_image_height, f_out);
	// fclose(f_out);
}