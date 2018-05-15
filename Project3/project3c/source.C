#include <source.h>
#define NULL __null

Source::Source(void) {
	image = NULL;
}

virtual void Execute(void) = 0;

Pixel getOutput() {
	return image.pixel;
}
