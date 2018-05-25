#include <image.h>

#ifndef SOURCE_H
#define SOURCE_H
class Source {
public:
	Source(void);
	
protected:
	Image source_image;
	virtual void Execute(void) = 0;

public:
	virtual void Update(void) = 0;
	Image* GetOutput();
};

#endif
