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

R3 R3::operator * (R3 timesVec)
{
	R3 result(_z * timesVec.z(), _y * timesVec.y(), _x * timesVec.x());
	return result;
}

R3 R3::operator / (R3 timesVec)
{
	R3 result(_z / timesVec.z(), _y / timesVec.y(), _x / timesVec.x());
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

void R3::operator *= (R3 times)
{
	_z *= times.z();
	_y *= times.y();
	_x *= times.x();
}

void R3::operator /= (R3 times)
{
	_z /= times.z();
	_y /= times.y();
	_x /= times.x();
}

R3 R3::operator + (double toAdd)
{
  R3 result(_x + toAdd, _y + toAdd,  _z + toAdd;
	return result;
}

R3 R3::operator - (double toAdd)
{
  R3 result(_x - toAdd, _y - toAdd,  _z - toAdd);
	return result;
}

R3 R3::operator * (double timesVec)
{
	R3 double(_z * timesVec, _y * timesVec, _x * timesVec);
	return result;
}

R3 R3::operator / (double timesVec)
{
	R3 result(_z / timesVec, _y / timesVec, _x / timesVec);
	return result;
}

void R3::operator += (double toAdd)
{
	_z += toAdd;
	_y += toAdd;
	_x += toAdd;
}

void R3::operator -= (double toAdd)
{
	_z -= toAdd;
	_y -= toAdd;
	_x -= toAdd;
}

void R3::operator *= (double times)
{
	_z *= times;
	_y *= times;
	_x *= times;
}

void R3::operator /= (double times)
{
	_z /= times;
	_y /= times;
	_x /= times;
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
