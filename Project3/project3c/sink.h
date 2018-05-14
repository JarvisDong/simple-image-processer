#ifndef SINK_H
#define SINK_H
class Sink {
public:
	Sink(void);
	virtual ~Sink();

private:
	Image *image1;
	Image *image2;
public:
	void setInput(Image *img);
	void setInput2(Image *img);
}
#endif