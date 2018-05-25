#include <image.h>
#include <sink.h>
#include <source.h>

class Filter : public Sink, public Source {
	void Update(void);
};

class Shrinker : public Filter {
public:
	Shrinker(void);
	void Execute(void);
};

class LRCombine : public Filter {
public:
	LRCombine(void);
	void Execute(void);
};

class TBCombine : public Filter {
public:
	TBCombine(void);
	void Execute(void);

};

class Blender : public Filter
{
public:
	Blender();
protected:
	double factor, factor2;
public:
	void SetFactor(double f);
	void Execute(void);
};

