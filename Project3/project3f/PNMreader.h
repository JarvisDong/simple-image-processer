#include <stdio.h>
#include <source.h>

#ifndef PNMREADER_H
#define PNMREADER_H
class PNMreader : public Source {
public:
	PNMreader(char *f);
	~PNMreader();
	virtual void Execute();
	virtual void Update();
private:
	char *filename;
};
#endif