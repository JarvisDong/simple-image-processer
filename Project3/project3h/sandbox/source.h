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
    virtual const char * SourceName() = 0;
};

#endif

#ifndef COLOR_H
#define COLOR_H

class Color : public Source {
public:
	const char *SourceName() {return "Color";}
	void Execute();
	virtual void Update();
	Color();
	Color(int w, int h, unsigned char r, unsigned char g, unsigned char b);
protected:
	int width, height;
	unsigned char red, green, blue;
};

#endif