#include "Shape.hpp"

class TrianglePrism : public Shape {
public:
	TrianglePrism();
	TrianglePrism(double a, double b, double depth, double angle);
	TrianglePrism(double a,double b,double depth,double angle, float x, float y, float z, float red, float green, float blue, float rotation);
	~TrianglePrism();
	void draw();

private:
	double a;
	double b;
	double depth;
	double angle;

};

