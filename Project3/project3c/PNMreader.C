#include <PNMreader.h>
#include <stdio.h>
#include <string.h>

PNMreader::PNMreader(char *f) {
	// make a string copy
	filename = new char[strlen(f)+1];
	int len = strlen(f);
	for (int i=0; i<len; i++) {
		filename[i] = f[i];
	}
	filename[len] = "\0";

	char magicNum[128];
	int w, h, maxval;
	FILE *f_in = fopen(filename, "r");
	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &w, &h, &maxval);
	source_image.ResetSize(w, h);

}

PNMreader::~PNMreader() {
	delete [] filename;
}

void
PNMreader::Execute() {
	fread(source_image.pixel, sizeof(Pixel), source_image.height*source_image.width, f_in);
	fclose(f_in);
}