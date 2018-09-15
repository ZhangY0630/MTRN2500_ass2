
#include "Shape.hpp"

#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#elif defined(WIN32)
#include <Windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#endif


Shape::Shape() {
	x = y = z = 0.0;
	rotation = 0.0;
	red = green = blue = 1.0;
};

Shape::Shape(double x_, double y_, double z_) {
	x = x_;
	y = y_;
	z = z_;

	rotation = 0.0;
	red = green = blue = 1.0;
};

Shape::Shape(double x_, double y_, double z_, double rotation_) {

	x = x_;
	y = y_;
	z = z_;

	rotation = rotation_;
	red = green = blue = 1.0;
};

Shape::~Shape() {
}

double Shape::getX() {
	return x;
};

double Shape::getY() {
	return y;
};

double Shape::getZ() {
	return z;
};

double Shape::getRotation() {
	return rotation;
};

void Shape::setX(double x_) {
	x = x_;
};

void Shape::setY(double y_) {
	y = y_;
};

void Shape::setZ(double z_) {
	z = z_;
};

void Shape::setRotation(double rotation_) {
	rotation = rotation_;
};


void Shape::setPosition(double x_, double y_, double z_) {
	x = x_;
	y = y_;
	z = z_;
};

void Shape::positionInGL() {
	glTranslated(x, y, z);
	glRotated(-rotation, 0, 1, 0);
};

void Shape::setColorInGL() {
	glColor3f(red, green, blue);
};

double Shape::getRed() {
	return red;
};

double Shape::getGreen() {
	return green;
};

double Shape::getBlue() {
	return blue;
};

void Shape::setColor(float red_, float green_, float blue_) {
	red = red_;
	green = green_;
	blue = blue_;
};

void Rectprism::setrectprism(double base_, double height_, double length_)
{
	base = base_;
	height = height_;
	length = length_;
}

void Rectprism::draw()
{
	//front
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(x + base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y - length / 2, z + height / 2);
	glVertex3f(x + base / 2, y - length / 2, z + height / 2);
	glEnd();
	glPopMatrix();
	//back
	glPushMatrix();
	glTranslated(0, 0,-height);
	glBegin(GL_QUADS);
	glVertex3f(x + base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y - length / 2, z + height / 2);
	glVertex3f(x + base / 2, y - length / 2, z + height / 2);
	glEnd();
	glPopMatrix();



	//left
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(x + base / 2, y + length / 2, z + height / 2);
	glVertex3f(x + base / 2, y + length / 2, z - height / 2);
	glVertex3f(x + base / 2, y - length / 2, z - height / 2);
	glVertex3f(x + base / 2, y - length / 2, z + height / 2);
	glEnd();
	glPopMatrix();
	//right
	glPushMatrix();
	glTranslated(-base , 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(x + base / 2, y + length / 2, z + height / 2);
	glVertex3f(x + base / 2, y + length / 2, z - height / 2);
	glVertex3f(x + base / 2, y - length / 2, z - height / 2);
	glVertex3f(x + base / 2, y - length / 2, z + height / 2);
	glEnd();
	glPopMatrix();
	//top
	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(x + base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y - length / 2, z - height / 2);
	glVertex3f(x + base / 2, y - length / 2, z - height / 2);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslated(0, -length, 0);
	glBegin(GL_QUADS);
	glVertex3f(x + base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y + length / 2, z + height / 2);
	glVertex3f(x - base / 2, y + length / 2, z - height / 2);
	glVertex3f(x + base / 2, y + length / 2, z - height / 2);
	glEnd();
	glPopMatrix();

}

void Triprism::setcoordiniate(Coordinate one, Coordinate two, Coordinate three)
{
	First_p = one;
	Second_p = two;
	Third_p = three;
}

void Triprism::setheight(double height_)
{
	height = height_;
}

void Triprism::draw()
{
	
	glBegin(GL_TRIANGLES);
	/*
	glVertex3f(First_p.GetX()+x,First_p.GetY()+y,First_p.GetZ()+z);
	glVertex3f(Second_p.GetX()+x, Second_p.GetY()+y, Second_p.GetZ()+z);
	glVertex3f(Third_p.GetX()+x, Third_p.GetY()+y, Third_p.GetZ()+z);
	*/
	glVertex3f(3, 0, 3);
	glVertex3f(-3, 0, 3);
	glVertex3f(0, 0, 0);
	glEnd();
	

}
