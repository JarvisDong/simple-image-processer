#include <stdio.h>
#include <string.h>
#include <image.h>
#include <PNMwriter.h>
#include <iostream>

using namespace std;

PNMwriter::PNMwriter(void) {;}

void
PNMwriter::Write(char *filename) {
	if (sink_image == NULL) {
		cerr << "no image to write!" << endl;
		exit(EXIT_FAILURE);
	}
	
	else{
    int sink_image_width = sink_image->getWidth();
    int sink_image_height = sink_image->getHeight();
    Pixel *sink_image_pixel = sink_image->getPixel();

    FILE *f_out = fopen(filename, "w");
	fprintf(f_out, "P6\n%d %d\n%d\n", sink_image_width, sink_image_height, 255);
	fwrite(sink_image_pixel, sizeof(Pixel), sink_image_width * sink_image_height, f_out);
	fclose(f_out);		
	}

}

const char *
PNMwriter::SinkName() {
	const char *msg;
	msg = "PNMwriter";
	return msg;
}