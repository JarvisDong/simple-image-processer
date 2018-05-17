#include <stdio.h>
#include <sink.h>

#ifndef PNMWRITER_H
#define PNMWRITER_H
class PNMwriterCPP : public Sink {
public:
	PNMwriterCPP(void);

public:
	void Write(char *filename);
};

#endif