#include <source.h>
#include <image.h>
#include <logging.h>

Source::Source() {
    source_image.setSource(this);
}

Image*
Source::GetOutput() {return &source_image;};
