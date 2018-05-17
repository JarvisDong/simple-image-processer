#include <image.h>
#include <sink.h>
#include <source.h>

#ifndef FILTER_H
#define FILTER_H
class Filter : public Sink, public Source {
public:
	Filter(void);
};
#endif


#ifndef SHRINKER_H
#define SHRINKER_H
class Shrinker : public Filter {
public:
	Shrinker(void);
	void Execute(void);
};
#endif

#ifndef LRCOMBINE_H
#define LRCOMBINE_H
class LRCombine : public Filter {
public:
	LRCombine(void);
	void Execute(void);
};
#endif

#ifndef TBCOMBINE_H
#define TBCOMBINE_H
class TBCombine : public Filter {
public:
	TBCombine(void);
	void Execute(void);

};
#endif

#ifndef BLENDER_H
#define BLENDER_H
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

#endif
