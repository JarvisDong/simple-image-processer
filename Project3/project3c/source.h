#include <image.h>

#ifndef SOURCE_H
#define SOURCE_H
class Source {
public:
	Source(void);
	
protected:
	Image source_image;

public:
	virtual void Execute(void) = 0;
	Image* GetOutput() {return &source_image;};
};

#endif
