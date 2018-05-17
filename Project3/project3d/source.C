#include <source.h>
#include <image.h>

Source::Source(void) {;}

Image*
Source::GetOutput() {return &source_image;};
