#include "Shape.hpp"
#include <iostream>
#include "Cylinder.h"//self defined ""
#include <GL/glut.h> //system defined library <>


Cylinder::Cylinder()
{
	radius=10;
	Cylinderlength=10;
	rolling = 0;
}
/*
Cylinder::Cylinder(double radius, double Cylinderlength)
{
	this->radius = radius;
	this->Cylinderlength = Cylinderlength;
	rolling = 0;
}
*/

Cylinder::Cylinder(double radius, double Cylinderlength, float x, float y, float z, float red, float green, float blue, float rotation)
{
	this->radius = radius;
	this->Cylinderlength = Cylinderlength;
	Shape::setX(x);
	Shape::setY(y);
	Shape::setZ(z);
	Shape::setColor(red, green, blue);
	Shape::setRotation(rotation);
	rolling = 0;
}

Cylinder::~Cylinder()
{

}

void Cylinder::draw()
{
	glPushMatrix();
	positionInGL(); //steering inside
	setColorInGL();

	GLUquadric*bottomcircle = gluNewQuadric();
	GLUquadric*CylinderWall = gluNewQuadric();
	

	glRotated(rolling, 1,0, 0); //for rolling

	gluDisk(bottomcircle, 0, radius, 5, 1);
	glTranslated(0, 0, Cylinderlength);//  glTranslated(x,y,z), move x,y,z position
	gluDisk(bottomcircle, 0, radius, 5, 1);
	glTranslated(0, 0, -Cylinderlength); //move back x,y,z position
	gluCylinder(CylinderWall, radius, radius, Cylinderlength, 5, 1);

	glPopMatrix();
}

double Cylinder::Getspeed()
{
	return speed;
}


//parameter comes from myVehicle draw()
void Cylinder::setRolling(double speed) {
	std::cout << speed << std::endl;
	this->speed = speed;
	rolling = rolling+speed;//can change to any linear formula
}