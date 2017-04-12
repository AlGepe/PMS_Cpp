#include <Solid.h>

Solid::Solid()
{
	// Whatever constructor needs
	simData = new Data();
}

void Solid::calculateNeighbours()
{
	// Create necessary variables
	Particle iParticle;
	double dist_x = .0,
				 dist_y = .0,
				 dist_z = .0,
				 distSqrt = .0,
				 radiusSqrt = simData->_sigma*simData->_sigma*(simData->_extraCutOff+simData->_cutOffRadius)*(simData->_extraCutOff+simData->_cutOffRadius);

	maxDisplacement(.0);

	for (int i = .0; i < _particleSet.size()-1; i++)//recheck syntaxis
	{// Last particle does not have neighbours as its already a neighbour of all possible
		Particle tParticle = _particleSet[i];
		Particle * iParticle  = &tParticle;
		iParticle->clearVecinity();
		for (int j = i+1; j < _particleSet.size(); j++)
		{ // All particles nor already checked
			Particle tempParticle = _particleSet[j];
			Particle * jParticle = &tempParticle;
			// Calculate distances
			dist_x = iParticle->position().x() - jParticle->position().x();
			dist_y = iParticle->position().y() - jParticle->position().y();
			dist_z = iParticle->position().z() - jParticle->position().z();
			// BC, no-edges
			dist_y = dist_y - _L * std::floor(dist_y/L);
			dist_y = dist_x - _L * std::floor(dist_x/L);
			dist_z = dist_z - _L * std::floor(dist_z/L);

			distSqrt = dist_x*dist_x + dist_y*dist_y + dist_z*dist_z;
			if(distSqrt < radiusSqrt)
			{// If closer than cut-off + margin, it's neighbour
				iParticle->vecinity().push_back(&jParticle);
			}
		}
	}
}	

double Solid::bring2solid(double x)
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

double Solid::gauss()
{
	double a1 = 3.949846138,
				 a3 = 0.252408784,
				 a5 = 0.076542912,
				 a7 = 0.008355968,
				 a9 = 0.029899776,
				 sum = .0,
				 r,
				 r2;
	for (int i = .0; i <12; i++) { sum += ranf(); } // Look for random number in c++ library
	r = (sum-6.0) /4;
	r2 = r*r;
	return ((((a9*r2+a7)*r2+a5)*r2+a3)*r2+a1)*r;
}

double Solid::ranf()
{//Until random function from library used
	int l = 1029, 
			c = 221591,
			m = 1048576;
	_seed = (_seed*l+c)%m;
	return std::floor (_seed/m);
}

void Solid::nexStep(LennarJones f)
{
	double dt = simData->_timeStep,
				 tempX = .0,
				 tempY = .0,
				 tempZ = .0,
				 k = .0;
	for(auto particle : _particleSet)
	{
		// Great place to test operator overload
		tempX = particle.velocity().x() * dt + .5*particle.acceleration().x()*dt*dt;
		tempY = particle.velocity().y() * dt + .5*particle.acceleration().y()*dt*dt;
		tempZ = particle.velocity().z() * dt + .5*particle.acceleration().z()*dt*dt;
		double displacement = MATHSQRT (LOOK IT UP);

		// change to binary operator
		if (_maxDisplacement < displacement) 
		{ 
			_maxDisplacement = displacement; 
		}

		R3 tempVector(tempX, tempY, tempZ);
		particle.position(tempVector);

		tempVector = particle.acceleration() * .5;
		tempVector = tempVector + particle.velocity();
		// tempX = particle.velocity().x() + .5 * particle.acceleration().x();
		// tempY = particle.velocity().y() + .5 * particle.acceleration().y();
		// tempZ = particle.velocity().z() + .5 * particle.acceleration().z();
	
		particle.velocity(tempVector);
	}
}

void Solid::lennardJonesValues(LennarJones f)
{
	double u = 0,
				 sigma = simData->_sigma,
				 fourepsilon = 4.0*simData->_epsilon,
				 rc = sigma*simData->_cutOffRadius,
				 m = simData->_mass,
				 src = sigma/rc,
				 src2 = src*src,
				 src6 = src2*src2*src2,
				 //Potential at the cut off radious
				 vc = fourepsilon*(src6*src6-src6),
				 // Derivative of the potential at the cut off radious
				 vr_discontinuity = 6.0*fourepsilon/rc*(2.0*src6*src6-src6),
				 distx,
				 disty,
				 distz,
				 distx2,
				 disty2,
				 distz2,
				 distr,
				 distr2,
				 sr2,
				 sr6,
				 fr = 0.0,
				 frij = 0.0,
				 v = 0.0, //
				 vij,
				 fx,
				 fy,
				 fz,
				 counts = 0;
	for (auto p : _particleSet) p.acceleration(R3 zero(0,0,0));
	bool  onlyfirstp = true;
	for (auto p	: _particleSet)
	{
		for (auto q : p.vecinity())
		{
			distx = p.position().x()-q.position().x();
			disty = p.position().y()-q.position().y();
			distz = p.position().z()-q.position().z();

			// BC "infinite" lattice
			distx = distx-_L*std::floor(distx/_L);
			disty = disty-_L*std::floor(disty/_L);
			distz = distz-_L*std::floor(distz/_L);

			distx2 = distx*distx;
			disty2 = disty*disty;
			distz2 = distz*distz;

			// Euclidian distance
			distr2 = distx2 + disty2 + distz2;
			distr =MATHSQRT(distr2);


			//Not all of the particles in the vecinity list are in a distance less or iqual to rc but, if I do the condition, most of the U values are zero. UNITS?
			//if(distr <= rc)
			sr2 = sigma * sigma / distr2;
			sr6 = sr2 * sr2 * sr2;

			vij = fourepsilon * (sr6 * sr6-sr6);
			if(onlyfirstp) f.register(distr, vij);
			v += vij;
			frij = 6.*fourepsilon * (2.*sr6*sr6-sr6);
			fr=frij/distr2;
			fx=fr*distx;
			fy=fr*disty;
			fz=fr*distz;
			p.acceleration(R3 newAcc(fx/m, fy/m, fz/m));
			q.acceleration(R3 newAcc(fx/m, fy/m, fz/m));
			counts++;
			u = v + vr_discontinuity*(distr-rc);
			// end if distr<=rc
		}
		onlyfirstp = false;
	}
	energy.u(v-vc*counts)/particleSet.size();
}

void Solid::Init()
{
	int Nc = simData.Nc;
	double mass = simData.mass,
				 tempSqrt = MATHSQRT(simData.temperature),
				 ro = simData.ro;
	R3 sumVel(); // Default is (0,0,0)
	R3 zeroVec();
	L = Nc*simData.sigma * CHCKMATH => (4*mass/ro)^1./3.;
	numParticles = 4* Nc*Nc*Nc;
	vector<Particle> solidParticles(numParticles);
	EneryValue energy(0., 0.);
	cell = L/Nc;
	solidParticles[0] = Particle(); // Default constructor puts particle at ((0,0,0),(0,0,0),(0,0,0)) (x,v,a)
	R3 posInit(cell/2., cell/2., 0.);
	solidParticles[1] = Particle(posInit, zeroVec, zeroVec);
	posInit.x(.0);
	posInit.z(cell/2.);
	solidParticles[2] = Particle(posInit, zeroVec, zeroVec);
	posInit.x(cell/2.);
	posInit.y(.0);
	solidParticles[3] = Particle(posInit, zeroVec, zeroVec);
	int m;
	for (int iz = 0; iz < Nc; iz++;) 
	{ // Particle position initialization
		for (int iy = 0; iy < Nc; iy++;)
		{
			for (int ix = 0; ix < Nc; ix++;)
			{
				if (m > 0)
				{
					for (int iref = 0; iref < 4; iref++;)
					{
						/*
						 * THIS DEFO NEEDS OVERLOADING OPERATORS on R3
						 */
						posInit = solidParticles[iref].position() + cell*ix);
						solidParticles[iref+m] = Particle(posInit, zeroVec, zeroVec);
					} //iref
				} //m
				m += 4;
			} //ix
		} //iy
	} //iz

	for (auto particle : solidParticles) // Assuming overloaded operators
	{
		particle.position(particle.position() - .5*L); // shift positions
		R3 gauss3D(gauss(), gauss(), gauss());
		particle.velocity(gauss3D * tempSqrt);
		sumVel += gauss3D;
	}

	sumVel = sumVel/numParticles; // For BC => V_solid = 0

	for (auto  particle : particleSet)
	{
		particle.velocity(particle.velocity() - sumVel); // So that Total momentum = 0
	}

	// Maybe test here would be nice to ensure V_solid = 0

	/*
	 * Continues with copying line 91 from Init.test.java
	 HERE TO FIGURE OUT HOW TO INITIALIZE sample

	 */
}
