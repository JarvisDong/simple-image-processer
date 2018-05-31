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

