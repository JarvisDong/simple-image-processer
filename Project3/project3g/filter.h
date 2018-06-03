#include <image.h>
#include <sink.h>
#include <source.h>

class Filter : public Sink, public Source {
public:
    virtual const char * FilterName(void) = 0;
    virtual const char * SourceName();
    virtual const char * SinkName();
    virtual int GetNumberofInputs() = 0;
    void Update();
};

class SingleInputFilter : public Filter {
public:
    virtual int GetNumberofInputs() {return 1;}
};

class DoubleInputFilter : public Filter {
public:
    virtual int GetNumberofInputs() {return 2;}
};

class Shrinker : public SingleInputFilter {
public:
	Shrinker(void);
	const char * FilterName() { return "Shrinker"; };
	void Execute(void);
};

class LRCombine : public DoubleInputFilter {
public:
	LRCombine(void);
    const char * FilterName() { return "LRConcat"; };
	void Execute(void);
};

class TBCombine : public DoubleInputFilter {
public:
	TBCombine(void);
    const char * FilterName() { return "TBConcat"; };
	void Execute(void);

};

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

// add 5 new filters
// 1) Mirror
// 2) Rotate
// 3) Subtract
// 4) Grayscale
// 5) Blur

class Mirror : public SingleInputFilter {
public:
	const char *FilterName() {return "Mirror";}
	void Execute();
};

class Rotate : public SingleInputFilter {
public:
	const char *FilterName() {return "Rotate";}
	void Execute();
};

class Subtract : public DoubleInputFilter {
public:
	const char *FilterName() {return "Subtract";}
	void Execute();
};

class Grayscale : public SingleInputFilter {
public:
	const char *FilterName() {return "Grayscale";}
	void Execute();
};

class Blur : public SingleInputFilter {
public:
	const char *FilterName() {return "Blur";}
	void Execute();
};

