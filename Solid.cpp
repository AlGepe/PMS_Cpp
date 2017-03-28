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
			{
				iParticle->vecinity()->append(jParticle);
			}
		}
	}
}	
