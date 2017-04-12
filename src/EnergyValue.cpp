#include "EnergyValue.h"

EnergyValue::EnergyValue(double u, double k) :
	_u(u),
	_k(k)
{}

/*
 * Setters
 */
void EnergyValue::u(double newU)
{
	_u = newU;
}

void EnergyValue::k(double newK)
{
	_k = newK;
}

/*
 * Getters
 */
double EnergyValue::u()
{
	return _u;
}

double EnergyValue::k()
{
	return _k;
}

