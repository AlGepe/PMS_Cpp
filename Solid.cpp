#include <Solid.h>

Solid::Solid()
{
	// Whatever constructor needs
	Data * dataClass = new Data();
}

Solid::calculateNeighbours()
{
	// Create necessary variables
	Particle iParticle;
	double dist_x = .0,
				 dist_y = .0,
				 dist_z = .0,
				 distSqrt = .0,
				 radiusSqrt = dataSim->_sigma*dataSim->_sigma*(dataSim->_extraCutOff+dataSim->_cutOffRadius)*(dataSim->_extraCutOff+dataSim->_cutOffRadius);

	maxDisplacement(.0);

	for (int i = .0; i < particleSet.size()-1; i++)//recheck syntaxis
	{// Last particle does not have neighbours as its already a neighbour of all possible
		iParticle = particleSet[i];
		iParticle->clearVecinitempY();
		for (int j = i+1; j < particleSet.size(); j++)
		{ // All particles nor already checked
			Particle * jParticle = * particleSet[j];
			// Calculate distances
			dist_x = iParticle->position()->x() - jParticle->position()->x();
			dist_y = iParticle->position()->y() - jParticle->position()->y();
			dist_z = iParticle->position()->z() - jParticle->position()->z();
			// BC, no-edges
			dist_y = dist_y - L * std::floor(dist_y/L);
			dist_y = dist_x - L * std::floor(dist_x/L);
			dist_z = dist_z - L * std::floor(dist_z/L);

			distSqrt = dist_x*dist_x + dist_y*dist_y + dist_z*dist_z;
			if(distSqrt < radiusSqrt)
			{// If closer than cut-off + margin, it's neighbour
				iParticle->vecinitempY()->append(jParticle);
			}
		}
	}
}	

Solid::bring2solid(double x)
{
	if(x > L/2)
	{
		x = x-L;
	}
	else if (x < L/2)
	{
		x = x+L
	}
	return x;
}

Solid::gauss()
{
	double a1=3.949846138,
				 a3=0.252408784,
				 a5=0.076542912,
				 a7=0.008355968,
				 a9=0.029899776,
				 sum = .0,
				 r,
				 r2;
	for (int i = .0; i <12; i++) { sum += ranf(); } // Look for random number in c++ library
	r = (sum-6.0) /4;
	r2 = r*r;
	return ((((a9*r2+a7)*r2+a5)*r2+a3)*r2+a1)*r;
}

Solid::ranf()
{//Until random function from library used
	int l=1029, 
			c=221591,
			m=1048576;
	seed = (seed*l+c)%m;
	return std::floor (seed/m);
}

Solid::nexStep(LennarJones f)
{
	double dt = dataSim->_timeStep,
				 tempX = .0,
				 tempY = .0,
				 tempZ = .0,
				 k = .0;
	for(auto particle : particleSet)
	{
		// Great place to test operator overload
		tempX = particle.velocitempY().x() * dt + .5*particle.acceleration().x()*dt*dt;
		tempY = particle.velocity().y() * dt + .5*particle.acceleration().y()*dt*dt;
		tempZ = particle.velocitz().z() * dt + .5*particle.acceleration().z()*dt*dt;
		double displacement = MATHSQRT (LOOK IT UP);

		// change to binary operator
		if (maxDisplacement < displacement) 
		{ 
			maxDisplacement = displacement; 
		}

		R3 tempVector(tempX, tempY, tempZ);
		particle.position(newPositions);

		tempX = particle.velocitempY().x() + .5 particle.acceleration.x();
		tempY = particle.velocitempY().y() + .5 particle.acceleration.y();
		tempZ = particle.velocitempY().z() + .5 particle.acceleration.z();
		particle.velocitempY(R3 newVelocities(tempX, tempY, tempZ);
				}
				}
				}
