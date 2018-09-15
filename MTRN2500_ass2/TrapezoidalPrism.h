#include "Shape.hpp"

class TrapezoidalPrism : public Shape {
public:
	TrapezoidalPrism();
	TrapezoidalPrism(double a, double b, double height, double depth,double aOffset);
	TrapezoidalPrism(double a, double b, double height, double depth, double aOffset, float x, float y, float z, float red, float green, float blue, float rotation);
	~TrapezoidalPrism();
	void draw();

private:
	double a;
	double b;
	double depth;
	double height;
	double aOffset;
};

