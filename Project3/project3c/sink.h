#include <image.h>

#ifndef SINK_H
#define SINK_H
class Sink {
public:
	Sink(void);
protected:
	Image *sink_image;
	Image *sink_image2;
public:
	void SetInput(Image *img) {sink_image = img;};
	void SetInput2(Image *img) {sink_image2 = img;};
};

#endif
