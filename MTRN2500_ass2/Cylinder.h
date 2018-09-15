#include "Shape.hpp"


class Cylinder : public Shape {

public:
	Cylinder();
	//Cylinder(double radius, double Cylinderlength);
	Cylinder(double radius, double Cylinderlength, float x, float y, float z, float red, float green, float blue, float rotation);
	~Cylinder();
	void draw();
	
	double Getspeed();
	void setRolling(double speed);
	
private:
	double radius;
	double Cylinderlength;
	double speed;
	double rolling;
};

