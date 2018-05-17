#include <PNMreaderCPP.h>
#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


PNMreaderCPP::PNMreaderCPP(char *f) {
	// make a string copy
	filename = new char[strlen(f)+1];
	strcpy(filename, f);
}

PNMreaderCPP::~PNMreaderCPP() {
	delete [] filename;
}

void
PNMreaderCPP::Execute() {
	char magicNum[128];
	int w, h, maxval;
	ifstream f_in;
	f_in.open(filename);
	f_in >> magicNum;
	f_in >> w >> h >> maxval;
	source_image.ResetSize(w, h);
	Pixel *buffer = source_image.getPixel();
	unsigned char r,g,b;

	for (int i = 0; i < w*h; i++) {
		f_in >> r >> noskipws >> g >> b;
		buffer[i].r = r;
		buffer[i].g = g;
		buffer[i].b = b;
	}
	f_in.close();
}