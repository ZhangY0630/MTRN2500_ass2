#include "Shape.hpp"
#include "Vehicle.hpp"
#include <GL/glut.h> //system defined library <>
#include "Messages.hpp"
//#include "Cylinder.h"

class MyVehicle : public Vehicle{
public:
	MyVehicle(); 
	MyVehicle(VehicleModel remote);
	~MyVehicle();

	VehicleModel getLocalmd();//upload
	void SetLocalmd();
	VehicleModel getremote();//download
	void Setremote();

	void SetLocal();//unpack localmd

	void draw();


private:
	VehicleModel Localmd; //upload pack
	VehicleModel remote; //download pack
	
};

