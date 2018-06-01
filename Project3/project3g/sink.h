#include <image.h>

#ifndef SINK_H
#define SINK_H

class Sink {
public:
	Sink(void);
protected:
	const Image *sink_image;
	const Image *sink_image2;
public:	
	void SetInput(const Image *img);
	void SetInput2(const Image *img);
	virtual const char * SinkName() = 0;
};
#endif
