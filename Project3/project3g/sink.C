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
