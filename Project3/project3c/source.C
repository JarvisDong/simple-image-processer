#include <source.h>
#define NULL __null

Source::Source(void) {
	image = NULL;
}

Source::~Source() {
	delete image;
}
