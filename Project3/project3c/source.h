#ifndef SOURCE_H
#define SOURCE_H
class Source {
public:
	Source(void);
	~Source();
	
private:
	Image image;

public:
	virtual void Execute(void) = 0;
	Pixel getOutput();
}
#endif
