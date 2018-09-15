#include "Shape.hpp"
#include "RectanglePrism.h" //self defined ""
#include <GL/glut.h> //system defined library <>


RectanglePrism::RectanglePrism()
{
	//Positive x to left
	lengthx = 10;
	lengthy = 10;
	lengthz = 10;

}

RectanglePrism::RectanglePrism(double lengthx, double lengthy, double lengthz)
{
	this->lengthx = lengthx;
	this->lengthy = lengthy;
	this->lengthz = lengthz;
}

RectanglePrism::RectanglePrism(double lengthx, double lengthy, double lengthz,float x, float y, float z, float red, float green, float blue, float rotation) {

	this->lengthx = lengthx;
	this->lengthy = lengthy;
	this->lengthz = lengthz;
	Shape::setX(x);
	Shape::setY(y);
	Shape::setZ(z);
	Shape::setColor(red, green, blue);
	Shape::setRotation(rotation);
}

RectanglePrism::~RectanglePrism()
{
}

void RectanglePrism::draw()
{
	glPushMatrix();
	positionInGL();
	setColorInGL();

	//bottom
	glBegin(GL_QUADS);
	glVertex3f(lengthx / 2, 0, -lengthz / 2);
	glVertex3f(-lengthx / 2, 0, -lengthz / 2);
	glVertex3f(-lengthx / 2, 0, lengthz / 2);
	glVertex3f(lengthx / 2, 0, lengthz / 2);
	glEnd();


	//right as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-lengthx / 2, 0, -lengthz / 2);
	glVertex3f(-lengthx / 2, 0, lengthz / 2);
	glVertex3f(-lengthx / 2, lengthy, lengthz / 2);
	glVertex3f(-lengthx / 2, lengthy, -lengthz / 2);
	glEnd();

	//left as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(lengthx / 2, 0, -lengthz / 2);
	glVertex3f(lengthx / 2, lengthy, -lengthz / 2);
	glVertex3f(lengthx / 2, lengthy, lengthz / 2);
	glVertex3f(lengthx / 2, 0, lengthz / 2);
	glEnd();
	

	//front as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-lengthx / 2, 0, lengthz / 2);
	glVertex3f(-lengthx / 2, lengthy, lengthz / 2);
	glVertex3f(lengthx / 2, lengthy, lengthz / 2);
	glVertex3f(lengthx / 2, 0, lengthz / 2);
	glEnd();


	//back as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(-lengthx / 2, 0, -lengthz / 2);
	glVertex3f(-lengthx / 2, lengthy, -lengthz / 2);
	glVertex3f(lengthx / 2, lengthy, -lengthz / 2);
	glVertex3f(lengthx / 2, 0, -lengthz / 2);
	glEnd();
	
	//top as reference begin screen
	glBegin(GL_QUADS);
	glVertex3f(lengthx / 2, lengthy, -lengthz / 2);
	glVertex3f(-lengthx / 2, lengthy, -lengthz / 2);
	glVertex3f(-lengthx / 2, lengthy, lengthz / 2);
	glVertex3f(lengthx / 2, lengthy, lengthz / 2);
	glEnd();
	glPopMatrix();
}
