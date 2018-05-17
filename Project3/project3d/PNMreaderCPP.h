#include <stdio.h>
#include <source.h>

#ifndef PNMREADER_H
#define PNMREADER_H
class PNMreaderCPP : public Source {
public:
	PNMreaderCPP(char *f);
	~PNMreaderCPP();
	virtual void Execute();
private:
	char *filename;
};
#endif