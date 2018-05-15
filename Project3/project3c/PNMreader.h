#include <stdio.h>

#ifndef PNMREADER_H
#define PNMREADER_H
class PNMreader : Source {
public:
	PNMreader(FILE *filename);
	~PNMreader();
}
#endif