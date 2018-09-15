#include "Shape.hpp"

class RectanglePrism : public Shape {
public:
	RectanglePrism();
	RectanglePrism(double lengthx, double lengthy, double lengthz);
	RectanglePrism(double lengthx, double lengthy, double lengthz, float x, float y, float z, float red, float green, float blue, float rotation);
	~RectanglePrism();
	void draw();

private:
	//Positive x to left
	double lengthx;
	double lengthy;
	double lengthz;
};
