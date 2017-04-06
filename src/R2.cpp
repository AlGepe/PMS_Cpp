#include <R2.h>

R2::R2(x,y) :
	_x(x),
	_y(y)
{}

/*
 * Getters
 */
double R2::x() {return _x;}
double R2::y() {return _y;}
/*
 * Setters
 */
void R2::x(double newX) { _x = newX;}
void R2::y(double newY) { _y = newY;}
