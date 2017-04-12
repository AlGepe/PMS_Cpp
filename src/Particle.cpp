#include <Particle.h>

Particle::Particle()
{
	_position = R3(0, 0, 0);
	_velocity = R3(0, 0, 0);
	_acceleration = R3(0, 0, 0);
}

Particle::Particle(R3 position, R3 velocity, R3 acceleration):
	_position(position),
	_velocity(velocity),
	_acceleration(acceleration)
	//_vecinity
{}

// should take 5mind to errradicate this aberration
void Particle::clearVecinity()
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
void Particle::vecinity(std::vector<Particle> newNeighbours)
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
