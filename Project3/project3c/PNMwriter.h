#include <stdio.h>
#include <sink.h>

#ifndef PNMWRITER_H
#define PNMWRITER_H
class PNMwriter : public Sink {
public:
	PNMwriter(char *filename);
};

#endif