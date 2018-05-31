#include <PNMreader.h>
#include <stdio.h>
#include <string.h>
#include <logging.h>

PNMreader::PNMreader(const char *f) {
	// make a string copy
	filename = new char[strlen(f)+1];
	int len = strlen(f);
	for (int i=0; i<len; i++) {
		filename[i] = f[i];
	}
	filename[len] = '\0';
}

PNMreader::~PNMreader() {
	delete [] filename;
}

void
PNMreader::Execute() {
	char magicNum[128];
	int w, h, maxval;
	FILE *f_in = fopen(filename, "r");

	if (f_in == NULL) {
		fprintf(stderr, "CANNOT open file %s\n", this->filename);
	}

	fscanf(f_in, "%s\n%d %d\n%d\n", magicNum, &w, &h, &maxval);

	if (strcmp(magicNum, "P6") != 0) {
		fprintf(stderr, "CANNOT read from file %s for it's not a type P6 PNM file", this->filename);
	}

	source_image.ResetSize(w, h);
	fread(source_image.getPixel(), sizeof(Pixel), source_image.getHeight()*source_image.getWidth(), f_in);
	fclose(f_in);
}

void PNMreader::Update() {
	char msg[128];
	sprintf(msg, "%s: about to execute\n", SourceName());
	Logger::LogEvent(msg);

	Execute();

    sprintf(msg, "%s: done executing\n", SourceName());
    Logger::LogEvent(msg);
}

const char * PNMreader::SourceName() {
	const char *msg;
	msg = "PNMreader";
	return msg;
}

