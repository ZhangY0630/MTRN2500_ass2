#include "Shape.hpp"
#include "TrianglePrism.h"
#include <GL/glut.h> //system defined library <>
#include <math.h> //math functions, DO NOT use <cmath>


TrianglePrism::TrianglePrism()
{
	a=10;
	b=10;
	depth=30;
	angle=45;
}

TrianglePrism::TrianglePrism(double a, double b, double depth, double angle)
{
	this->a = a;
	this->b = b;
	this->depth = depth;
	this->angle = angle;
}
TrianglePrism::TrianglePrism(double a, double b, double depth, double angle, float x, float y, float z, float red, float green, float blue, float rotation)
{
	this->a = a;
	this->b = b;
	this->depth = depth;
	this->angle = angle;
	Shape::setX(x);
	Shape::setY(y);
	Shape::setZ(z);
	Shape::setColor(red, green, blue);
	Shape::setRotation(rotation);
}





TrianglePrism::~TrianglePrism()
{
}

void TrianglePrism::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();

	double pi = 3.1415926535;
	
	
	//front as reference begin screen
	glBegin(GL_TRIANGLES);
	glVertex3f(a/2,0,-depth/2);
	glVertex3f(-a/2,0,-depth/2);
	glVertex3f((-a/2)+b*cos(angle*pi/180), b*sin(angle*pi/180), -depth/2);
	glEnd();
	
	//bottom as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-a / 2, 0, -depth / 2);
	glVertex3f(-a / 2, 0, depth / 2);
	glVertex3f(a / 2, 0, depth / 2);
	glVertex3f(a / 2, 0, -depth / 2);
	glEnd();
	
	//back as reference begin screen
	glBegin(GL_TRIANGLES);
	glVertex3f(a / 2, 0, depth / 2);
	glVertex3f(-a / 2, 0, depth / 2);
	glVertex3f((-a / 2) + b * cos(angle*pi / 180), b*sin(angle*pi / 180), depth / 2);
	glEnd();
	
	//right as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-a / 2, 0, -depth / 2);
	glVertex3f((-a / 2) + b * cos(angle*pi / 180), b*sin(angle*pi / 180), -depth / 2);
	glVertex3f((-a / 2) + b * cos(angle*pi / 180), b*sin(angle*pi / 180), depth / 2);
	glVertex3f(-a / 2, 0, depth / 2);
	glEnd();

	//left as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(a / 2, 0, -depth / 2);
	glVertex3f((-a / 2) + b * cos(angle*pi / 180), b*sin(angle*pi / 180), -depth / 2);
	glVertex3f((-a / 2) + b * cos(angle*pi / 180), b*sin(angle*pi / 180), depth / 2);
	glVertex3f(a / 2, 0, depth / 2);
	glEnd();
	glPopMatrix();
}
