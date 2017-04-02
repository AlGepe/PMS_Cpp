#include <R3.h>

// Constructor
R3::R3(double _x, double _y, double _z) :
	_x(x), 
	_y(y),
	_z(z)
{
}

R3 R3::operator + (R3 toAdd)
{
  R3 result(_x + toAdd.x(), _y + toAdd.y(),  _z + toAdd.z());
	return result;
}

R3 R3::operator - (R3 toAdd)
{
  R3 result(_x - toAdd.x(), _y - toAdd.y(),  _z - toAdd.z());
	return result;
}

void R3::operator += (R3 toAdd)
{
	_z += toAdd.z();
	_y += toAdd.y();
	_x += toAdd.x();
}

void R3::operator -= (R3 toAdd)
{
	_z -= toAdd.z();
	_y -= toAdd.y();
	_x -= toAdd.x();
}

void R3::operator *= (double times)
{
	_z *= times;
	_y *= times;
	_z *= times;
}

// Copy constructor
R3::R3(R3& sourceObject)
{
	_x = sourceObject.x();
	_y = sourceObject.y();
  _z = sourceObject.z();
}


/*
 * Getters
 */

double x()
{
	return _x;
}

double y()
{
	return _y;
}

double z()
{
	return _z;
}

/*
 * Setters
 */

void x(double newX)
{
	_x = newX;
}

void y(double newY)
{
	_y = newY;
}

void z(double newZ)
{
	_z = newZ;
}
