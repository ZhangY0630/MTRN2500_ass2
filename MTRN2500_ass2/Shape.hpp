
#ifndef MTRN3500_SHAPE_H
#define MTRN3500_SHAPE_H
class Coordinate {
public:
	Coordinate() = default;
	~Coordinate() = default;
	Coordinate(double x, double y) :x(x), y(y),z(z) {}
	double GetX() { return this->x; }
	double GetY() { return this->y; }
	double GetZ() { return this->z; }
	void Set(double x, double y, double z) { this->x = x, this->y, this->z = z; }

private:
	double x;
	double y;
	double z;
};
// Abstract class
class Shape {

public:
	Shape();
	Shape(double x_, double y_, double z_);
	Shape(double x_, double y_, double z_, double rotation_);
	virtual ~Shape();

	virtual void draw() = 0;

	double getX();
	double getY();
	double getZ();
	double getRotation();

	void setX(double x_);
	void setY(double y_);
	void setZ(double z_);
	void setRotation(double rotation_);

	void setPosition(double x_, double y_, double z_);

	void positionInGL();
	void setColorInGL();

	double getRed();
	double getGreen();
	double getBlue();
	void setColor(float red_, float green_, float blue_);



protected:
	double x, y, z;               // position
	double rotation;              // heading of the object in the horizontal plane (degrees)
	float red, green, blue;       // colour of object


};

class Rectprism : public Shape
{
public:
	void setrectprism(double base_, double height_, double length_);
	virtual void draw();
protected:
	double base, height, length;

};
class Triprism : public Shape
{
public:
	void setcoordiniate(Coordinate one, Coordinate two, Coordinate three);
	void setheight(double height_);
	virtual void draw();
	
protected:
	Coordinate First_p, Second_p, Third_p;
	double height;
};



#endif // for MTRN3500_SHAPE_H
