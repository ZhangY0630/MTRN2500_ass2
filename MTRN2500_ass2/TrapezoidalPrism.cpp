#include "Shape.hpp"
#include "TrapezoidalPrism.h"
#include <GL/glut.h> //system defined library <>
#include <math.h> //math functions, DO NOT use <cmath>


TrapezoidalPrism::TrapezoidalPrism()
{
	a=20;
	b=10;
	height=20;
	depth=20;
	aOffset=5;
	
}

TrapezoidalPrism::TrapezoidalPrism(double a, double b, double height, double depth, double aOffset)
{
	this->a = a;
	this->b = b;
	this->height = height;
	this->depth = depth;
	this->aOffset = aOffset;
}

TrapezoidalPrism::TrapezoidalPrism(double a, double b, double height, double depth, double aOffset, float x, float y, float z, float red, float green, float blue, float rotation)
{
	this->a = a;
	this->b = b;
	this->height = height;
	this->depth = depth;
	this->aOffset = aOffset;
	Shape::setX(x);
	Shape::setY(y);
	Shape::setZ(z);
	Shape::setColor(red, green, blue);
	Shape::setRotation(rotation);
}


TrapezoidalPrism::~TrapezoidalPrism()
{
	
}

void TrapezoidalPrism::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();

	//top as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f((-a / 2) + aOffset, height, -depth / 2);
	glVertex3f((-a / 2) + aOffset, height, depth / 2);
	glVertex3f((-a / 2) + b + aOffset, height, depth / 2);
	glVertex3f((-a / 2) + b + aOffset, height, -depth / 2);
	glEnd();


	//bottom as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(a / 2, 0, -depth / 2);
	glVertex3f(-a / 2, 0, -depth / 2);
	glVertex3f(-a / 2, 0, depth / 2);
	glVertex3f(a / 2, 0, depth / 2);
	glEnd();

	//front as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-a / 2, 0, -depth / 2);
	glVertex3f((-a / 2)+ aOffset, height , -depth / 2);
	glVertex3f((-a / 2) + b + aOffset, height , -depth / 2);
	glVertex3f(a / 2, 0, -depth / 2);
	glEnd();

	//back as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-a / 2, 0, depth / 2);
	glVertex3f((-a / 2) + aOffset, height, depth / 2);
	glVertex3f((-a / 2) + b + aOffset, height, depth / 2);
	glVertex3f(a / 2, 0, depth / 2);
	glEnd();

	//left as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(a / 2, 0, -depth / 2);
	glVertex3f((-a / 2) + b + aOffset, height, - depth / 2);
	glVertex3f((-a / 2) + b + aOffset, height, depth / 2);
	glVertex3f(a / 2, 0, depth / 2);
	glEnd();

	//right as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-a / 2, 0, -depth / 2);
	glVertex3f((-a / 2) + aOffset, height, -depth / 2);
	glVertex3f((-a / 2) + aOffset, height, depth / 2);
	glVertex3f(-a / 2, 0, depth / 2);
	glEnd();
	glPopMatrix();
	
}
