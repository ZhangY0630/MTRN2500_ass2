#include <iostream>
#include "MyVehicle.h"
#include "RectanglePrism.h"
#include"TrianglePrism.h"
#include"TrapezoidalPrism.h"
#include "Cylinder.h"
//system defined library <>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include"Shape.hpp"
#include "Vehicle.hpp"
#include "Messages.hpp"

MyVehicle::MyVehicle()
{
	SetLocalmd();
	Setremote();
	SetLocal();
}

MyVehicle::MyVehicle(VehicleModel remote)
{
	this->remote = remote;
	Setremote();
}


MyVehicle::~MyVehicle()
{

}

VehicleModel MyVehicle::getremote()
{
	return remote;
}

void MyVehicle::Setremote()//download, 
{
	Shape* shptr;
	std::vector<ShapeInit>::iterator a = remote.shapes.begin();//defined a interator a pointing to vector ShapeInit
	while (a != remote.shapes.end()) {
		if (a->type == RECTANGULAR_PRISM) {
			shptr = new RectanglePrism(a->params.rect.xlen, a->params.rect.ylen, a->params.rect.zlen, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation); //pointing to x, y, z in package
			addShape(shptr);//add a drawing list 
		}
		else if (a->type == CYLINDER) {
			shptr = new Cylinder(a->params.cyl.radius, a->params.cyl.depth, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation);
			addShape(shptr);
		}
		else if (a->type == TRIANGULAR_PRISM) {
			shptr = new TrianglePrism(a->params.tri.alen, a->params.tri.blen, a->params.tri.depth, a->params.tri.angle, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation);
			addShape(shptr);
		}

		else if (a->type == TRAPEZOIDAL_PRISM) {
			shptr = new TrapezoidalPrism(a->params.trap.alen, a->params.trap.blen, a->params.trap.height, a->params.trap.depth, a->params.trap.aoff, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation);
			addShape(shptr);
		}
		a++;
	}
}

void MyVehicle::SetLocal()
{
	Shape* shptr;
	std::vector<ShapeInit>::iterator c = Localmd.shapes.begin();
	while (c != Localmd.shapes.end()) {
		if (c->type == RECTANGULAR_PRISM) {
			shptr = new RectanglePrism(c->params.rect.xlen, c->params.rect.ylen, c->params.rect.zlen, c->xyz[0], c->xyz[1], c->xyz[2], c->rgb[0], c->rgb[1], c->rgb[2], c->rotation); //pointing to x, y, z in package
			addShape(shptr);//add a drawing list 
		}
		else if (c->type == CYLINDER) {
			shptr = new Cylinder(c->params.cyl.radius, c->params.cyl.depth, c->xyz[0], c->xyz[1], c->xyz[2], c->rgb[0], c->rgb[1], c->rgb[2], c->rotation);
			addShape(shptr);
		}
		else if (c->type == TRIANGULAR_PRISM) {
			shptr = new TrianglePrism(c->params.tri.alen, c->params.tri.blen, c->params.tri.depth, c->params.tri.angle, c->xyz[0], c->xyz[1], c->xyz[2], c->rgb[0], c->rgb[1], c->rgb[2], c->rotation);
			addShape(shptr);
		}

		else if (c->type == TRAPEZOIDAL_PRISM) {
			shptr = new TrapezoidalPrism(c->params.trap.alen, c->params.trap.blen, c->params.trap.height, c->params.trap.depth, c->params.trap.aoff, c->xyz[0], c->xyz[1], c->xyz[2], c->rgb[0], c->rgb[1], c->rgb[2], c->rotation);
			addShape(shptr);
		}
		c++;
	}
}




void MyVehicle::draw()
{
	std::vector<Shape*>::iterator b = shapes.begin();
	Cylinder* allwheels = dynamic_cast<Cylinder*> (*b);
	while (b != shapes.end()) {
		glPushMatrix();
		positionInGL(); //if no this line, car cannot move
		allwheels = dynamic_cast<Cylinder*>(*b);
		if (allwheels != NULL && (allwheels->getX()) > 0) { //front wheels rotating
			allwheels->setRotation(Vehicle::steering); //steering pass into Shape class
		}
		if (allwheels != NULL) { //back wheels rotating, (allwheels->getX()) < 0 restricting back wheels rotate
			allwheels->setRolling(Vehicle::speed); //speed pass to cylinder class
		}

		(*b)->draw();
		glPopMatrix();
		b++;
	}
}
