#include <sink.h>
#define NULL __null

Sink::Sink(void) {
	image1 = NULL;
	image2 = NULL;
}

Sink::~Sink() {
	delete image1;
	delete image2;
}

void setInput(image *img) {
	image1 = img;
}
void setInput2(image *img) {
	image2 = img;
}
