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

}

MyVehicle::MyVehicle(VehicleModel remote)
{
	this->remote = remote;
	Setremote();
}


MyVehicle::~MyVehicle()
{
	
}

VehicleModel MyVehicle::getLocalmd()
{
	return Localmd;
}

void MyVehicle::SetLocalmd()//upload to server
{
	
	//upload cylinderA1 front right 
	ShapeInit CylA1;
	CylA1.type = CYLINDER;
	CylA1.rgb[0] = 1;
	CylA1.rgb[1] = 0.4;
	CylA1.rgb[2] = 0;
	CylA1.xyz[0] = 1.5;//from message
	CylA1.xyz[1] = 0;
	CylA1.xyz[2] = 1.1;
	CylA1.params.cyl.radius = 0.4;//from messages
	CylA1.params.cyl.depth = 0.3;
	CylA1.params.cyl.isRolling = 1; //enable wheel rolling 1, disable wheel rolling 0
	CylA1.params.cyl.isSteering = 1;//enable steering 1, disable 0
	CylA1.rotation = 0;
	Localmd.shapes.push_back(CylA1);
	
	//upload cylinderA2 front left
	ShapeInit CylA2;
	CylA2.type = CYLINDER;
	CylA2.rgb[0] = 1;
	CylA2.rgb[1] = 0.4;
	CylA2.rgb[2] = 0;
	CylA2.xyz[0] = 1.5;//from message
	CylA2.xyz[1] = 0;
	CylA2.xyz[2] = -1.1;
	CylA2.params.cyl.radius = 0.4;//from messages
	CylA2.params.cyl.depth = 0.3;
	CylA2.params.cyl.isRolling = 1;
	CylA2.params.cyl.isSteering = 1;
	CylA2.rotation = 0;
	Localmd.shapes.push_back(CylA2);

	//upload cylinderA3 back right 
	ShapeInit CylA3;
	CylA3.type = CYLINDER;
	CylA3.rgb[0] = 0;
	CylA3.rgb[1] = 0;
	CylA3.rgb[2] = 1;
	CylA3.xyz[0] = -1.5;//from message
	CylA3.xyz[1] = 0;
	CylA3.xyz[2] = 1.1;
	CylA3.params.cyl.radius = 0.8;//from messages
	CylA3.params.cyl.depth = 0.3;
	CylA3.params.cyl.isRolling = 1;
	CylA3.params.cyl.isSteering = 0;
	CylA3.rotation = 0;
	Localmd.shapes.push_back(CylA3);

	//upload cylinderA4 back left
	ShapeInit CylA4;
	CylA4.type = CYLINDER;
	CylA4.rgb[0] = 0;
	CylA4.rgb[1] = 0;
	CylA4.rgb[2] = 1;
	CylA4.xyz[0] = -1.5;//from message
	CylA4.xyz[1] = 0;
	CylA4.xyz[2] = -1.1;
	CylA4.params.cyl.radius = 0.8;//from messages
	CylA4.params.cyl.depth = 0.3;
	CylA4.params.cyl.isRolling = 1;
	CylA4.params.cyl.isSteering = 0;
	CylA4.rotation = 0;
	Localmd.shapes.push_back(CylA4);
	
	//upload rectangle,it is a package
	ShapeInit Rectbody;
	Rectbody.type = RECTANGULAR_PRISM;
	Rectbody.rgb[0] = 0;
	Rectbody.rgb[1] = 1;
	Rectbody.rgb[2] = 0;
	Rectbody.xyz[0] = 0;//from message
	Rectbody.xyz[1] = 0.4;
	Rectbody.xyz[2] = 0;
	Rectbody.params.rect.xlen = 3;//from messages
	Rectbody.params.rect.ylen = 1;
	Rectbody.params.rect.zlen = 2;
	Rectbody.rotation = 0;
	Localmd.shapes.push_back(Rectbody);

	//upload trianglePrism
	ShapeInit trighead;
	trighead.type = TRIANGULAR_PRISM;
	trighead.rgb[0] = 1;
	trighead.rgb[1] = 0;
	trighead.rgb[2] = 0;
	trighead.xyz[0] = 2.5;//from message
	trighead.xyz[1] = 0.4;
	trighead.xyz[2] = 0;
	trighead.params.tri.alen = 2;//from messages
	trighead.params.tri.blen = 1;
	trighead.params.tri.angle = 90;
	trighead.params.tri.depth = 2;
	trighead.rotation = 0;
	Localmd.shapes.push_back(trighead);

	//upload trapezoidalPrism
	ShapeInit traptail;
	traptail.type = TRAPEZOIDAL_PRISM;
	traptail.rgb[0] = 0.8;
	traptail.rgb[1] = 0;
	traptail.rgb[2] = 0;
	traptail.xyz[0] = -2.5;//from message
	traptail.xyz[1] = 0.4;
	traptail.xyz[2] = 0;
	traptail.params.trap.alen = 2;//from messages
	traptail.params.trap.blen = 3;
	traptail.params.trap.height = 1;
	traptail.params.trap.aoff = 0;
	traptail.params.trap.depth = 2;
	traptail.rotation = 180;
	Localmd.shapes.push_back(traptail);
}

VehicleModel MyVehicle::getremote()
{
	return remote;
}

void MyVehicle::Setremote()//download from server
{
	Shape* shptr;
	std::vector<ShapeInit>::iterator a = remote.shapes.begin();//defined a interator a pointing to vector ShapeInit
		while (a != remote.shapes.end()) {
			if (a->type == RECTANGULAR_PRISM) {
				shptr = new RectanglePrism(a->params.rect.xlen, a->params.rect.ylen, a->params.rect.zlen, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation); //pointing to x, y, z in package
				addShape(shptr);//add a drawing list 
			}
			else if (a-> type == CYLINDER) {
				shptr = new Cylinder(a->params.cyl.radius, a->params.cyl.depth, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation);
				addShape(shptr);
			}
			else if (a->type == TRIANGULAR_PRISM) {
				shptr = new TrianglePrism(a->params.tri.alen, a->params.tri.blen, a->params.tri.depth, a->params.tri.angle, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation);
				addShape(shptr);
			}

			else if (a->type == TRAPEZOIDAL_PRISM) {
				shptr = new TrapezoidalPrism (a->params.trap.alen, a->params.trap.blen, a->params.trap.height, a->params.trap.depth, a->params.trap.aoff, a->xyz[0], a->xyz[1], a->xyz[2], a->rgb[0], a->rgb[1], a->rgb[2], a->rotation);
				addShape(shptr);
			}
			a++;
		}
}





void MyVehicle::draw()
{
	
		glPushMatrix();
		positionInGL(); 
		
		glPopMatrix();
		
	}
}
