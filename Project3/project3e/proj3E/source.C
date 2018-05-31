#include <source.h>
#include <image.h>

Source::Source() {
    source_image.setSource(this);
}

Image*
Source::GetOutput() {return &source_image;};
