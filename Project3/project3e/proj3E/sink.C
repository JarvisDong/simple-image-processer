#include <sink.h>
#include <image.h>
#define NULL __null

Sink::Sink(void) {
    sink_image = NULL;
    sink_image2 = NULL;
}

void
Sink::SetInput(Image *img) {
    sink_image = img;
}

void
Sink::SetInput2(Image *img) {
    sink_image2 = img;
}
