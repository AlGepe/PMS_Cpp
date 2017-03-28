#include <EneryValue.h>

EneryValue::EneryValue(double u, double k) :
	_u(u),
	_k(k)
{}

/*
 * Setters
 */
void EneryValue::u(double newU)
{
	_u = newU;
}

void EneryValue::k(double newK)
{
	_k = newK;
}

/*
 * Getters
 */
double EneryValue::u()
{
	return _u;
}

double EneryValue::k()
{
	return _k;
}

