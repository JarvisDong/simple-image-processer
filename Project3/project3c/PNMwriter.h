#include <stdio.h>

#ifndef PNMWRITER_H
#define PNMWRITER_H
class PNMwriter : Sink {
public:
	PNMwriter(void);
	void Write(FILE *filename);
}
#endif