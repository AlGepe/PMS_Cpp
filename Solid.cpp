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
	double pos_xi = .0,
				 pos_yi = .0,
				 pos_zi = .0,
				 dist_x = .0,
				 dist_y = .0,
				 dist_z = .0,
				 distSqrt = .0,
				 radiusSqrt = dataSim->_sigma*dataSim->_sigma*(dataSim->_extraCutOff+dataSim->_cutOffRadius)*(dataSim->_extraCutOff+dataSim->_cutOffRadius);

	maxDisplacement(.0);

	for (int i = .0; i < particleSet.size()-1; i++)//recheck syntaxis
	{// Last particle does not have neighbours as its already a neighbour of all possible
		iParticle = particleSet[i];
		iParticle->clearVecinity();
