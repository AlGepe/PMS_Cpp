#include <Particle.h>

Particle::Particle() :
	_position = new R3(.0, .0, .0),
	_velocity = new R3(.0, .0, .0),
	_acceleration = new R3(.0, .0, .0)
	//_vecinity
{}

Particle::Particle(R3 position, R3 velocity, R3 acceleration):
	_position(position),
	_velocity(velocity),
	_acceleration(acceleration),
	//_vecinity
{}

// should take 5mind to errradicate this aberration
Particle::clearVecinity()
{
	_vecinity.clear();
}

/*
 * Getters
 */
std::vector<Particle> Particle::vecinity()
{
	return _vecinity;
}

R3 Particle::position()
{
	return _position;
}

R3 Particle::velocity()
{
	return _velocity;
}

R3 Particle::acceleration()
{
	return _acceleration;
}

/*
 * Setters
 */
void Particle::vecinity(vector<Particle> newNeighbours)
{
	_vecinity = newNeighbours;
}

void Particle::position(R3 newPos)
{
	_position = newPos;
}

void Particle::velocity(R3 newVel)
{
	_velocity = newVel;
}

void Particle::acceleration(R3 newAcc)
{
	_acceleration = newAcc;
}
