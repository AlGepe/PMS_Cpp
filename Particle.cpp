#include <Particle.h>

Particle::Particle():
	_position = new R3(.0, .0, .0),
	_velocity = new R3(.0, .0, .0),
	_acceleration = new R3(.0, .0, .0),
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
Particle::vecinity()
{
	return _vecinity;
}

Particle::position()
{
	return _position;
}

Particle::velocity()
{
	return _velocity;
}

Particle::acceleration()
{
	return _acceleration;
}

/*
 * Setters
 */
Particle::vecinity(vector<Particle> newNeighbours)
{
	_vecinity = newNeighbours;
}

Particle::position(R3 newPos)
{
	_position = newPos;
}

Particle::velocity(R3 newVel)
{
	_velocity = newVel;
}

Particle::acceleration(R3 newAcc)
{
	_acceleration = newAcc;
}
