#include <stdio.h>
#include <source.h>

#ifndef PNMREADER_H
#define PNMREADER_H
class PNMreader : public Source {
public:
	PNMreader(char *filename);
	~PNMreader();
	virtual void Execute();
};
#endif