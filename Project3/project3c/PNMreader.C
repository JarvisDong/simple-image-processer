#include <PNMreader.h>
#include <stdio.h>

PNMreader::PNMreader(char *filename) {
	char magicNum[128];
	int w, h, maxval;
	FILE *f_in = fopen(filename, "r");
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &w, &h, &maxval);
	source_image.ResetSize(w, h);

}

PNMreader::~PNMreader() {
	delete [] source_image.getPixel();
}

void
PNMreader::Execute() {
	fread(source_image.pixel, sizeof(Pixel), source_image.height*source_image.width, f_in);
	fclose(f_in);
}