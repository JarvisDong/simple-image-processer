#include <image.h>
#include <sink.h>
#include <source.h>

class Filter : public Sink, public Source {
public:
    virtual const char * FilterName() = 0;
    virtual const char * SourceName() { return FilterName(); };
    virtual const char * SinkName() { return FilterName(); };
    virtual int GetNumberofInputs() {return 0;};
    void Update();
};

#ifndef SIF_H
#define SIF_H
class SingleInputFilter : public Filter {
public:
    virtual int GetNumberofInputs() {return 1;}
};
#endif

#ifndef DIF_H
#define DIF_H
class DoubleInputFilter : public Filter {
public:
    virtual int GetNumberofInputs() {return 2;}
};
#endif

#ifndef SHRINKER_H
#define SHRINKER_H
class Shrinker : public SingleInputFilter {
public:
	Shrinker(void);
	const char * FilterName() { return "Shrinker"; };
	void Execute(void);
};
#endif

#ifndef LRCOMBINE_H
#define LRCOMBINE_H
class LRCombine : public DoubleInputFilter {
public:
	LRCombine(void);
    const char * FilterName() { return "LRConcat"; };
	void Execute(void);
};
#endif

#ifndef TBCOMBINE_H
#define TBCOMBINE_H
class TBCombine : public DoubleInputFilter {
public:
	TBCombine(void);
    const char * FilterName() { return "TBConcat"; };
	void Execute(void);
};
#endif


#ifndef BLENDER_H
#define BLENDER_H
class Blender : public DoubleInputFilter
{
public:
	Blender();
protected:
	double factor, factor2;
public:
	void SetFactor(double f);
    const char * FilterName() { return "Blender"; };
	void Execute(void);
};
#endif
// add 5 new filters
// 1) Mirror
// 2) Rotate
// 3) Subtract
// 4) Grayscale
// 5) Blur

#ifndef MIRROR_H
#define MIRROR_H
class Mirror : public SingleInputFilter {
public:
	const char *FilterName() {return "Mirror";}
	void Execute();
};
#endif

#ifndef ROTATE_H
#define ROTATE_H
class Rotate : public SingleInputFilter {
public:
	const char *FilterName() {return "Rotate";}
	void Execute();
};
#endif

#ifndef SUBSTRACT_H
#define SUBSTRACT_H
class Subtract : public DoubleInputFilter {
public:
	const char *FilterName() {return "Subtract";}
	void Execute();
};
#endif

#ifndef GRAYSCALE_H
#define GRAYSCALE_H
class Grayscale : public SingleInputFilter {
public:
	const char *FilterName() {return "Grayscale";}
	void Execute();
};
#endif

#ifndef BLUR_H
#define GRAYSCALE_H
class Blur : public SingleInputFilter {
public:
	const char *FilterName() {return "Blur";}
	void Execute();
};
#endif
