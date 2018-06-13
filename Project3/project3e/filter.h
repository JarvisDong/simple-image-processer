#include <image.h>
#include <sink.h>
#include <source.h>

#ifndef FILTER_H
#define FILTER_H
class Filter : public Sink, public Source {
	void Update(void);
public:
	virtual int GetNumberofInputs() {return 0;}
};
#endif


#ifndef SIF_H
#define SIF_H
class SingleInputFiler: public Filter
{
    public:
        virtual int GetNumberofInputs() {return 1;}
};
#endif 

#ifndef DIF_H
#define DIF_H
class DoubleInputFiler: public Filter
{
    public:
        virtual int GetNumberofInputs() {return 2;}
};
#endif


#ifndef SHRINKER_H
#define SHRINKER_H
class Shrinker : public SingleInputFiler {
public:
	Shrinker(void);
	void Execute(void);
};
#endif

#ifndef LRCOMBINE_H
#define LRCOMBINE_H
class LRCombine : public DoubleInputFiler {
public:
	LRCombine(void);
	void Execute(void);
};
#endif

#ifndef TBCOMBINE_H
#define TBCOMBINE_H
class TBCombine : public DoubleInputFiler {
public:
	TBCombine(void);
	void Execute(void);

};
#endif

#ifndef BLENDER_H
#define BLENDER_H
class Blender : public DoubleInputFiler
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
