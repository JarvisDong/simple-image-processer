#ifndef SOURCE_H
#define SOURCE_H
class Source {
public:
	Source(void);
	
private:
	Image image;

public:
	virtual void Execute(void);
	Pixel getOutput();
}
#endif
