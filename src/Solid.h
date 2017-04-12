#ifndef SOLID_H
#define SOLID_H
#endif
#include <vector>
#include "EneryValue.h"
#include "Particle.h"
#include "LennarJones.h"

class Solid{
	private: 
		int _numParticles;
		int _numbRecalcNeigh;
		std::vector<Particle> _particleSample,
										 _particleSet,
										 _sampleInScope;
		double _L;
		double _maxDisplacement;
		EnergyValue _energySolid;
		int _seed;
			
	public:
		//Constructor
		Solid();

		void Init();
		void ranf();
		void gauss();
		void calculateNeighbours();
		void takeSample();
		double bind();
		void nexStep(LennarJones f);
		void lennardJonesValues(LennarJones f);
		//setters
		int numParticles();
		int numbRecalcNeigh();
		std::vector<Particle> particleSample();
		std::vector<Particle> particleSet();
		std::vector<Particle> sampleInScope();
		double L();
		double maxDisplacement();
		EnergyValue energySolid();
		int seed();
		
		//getters
		void numParticles();
		void numbRecalcNeigh();
		void particleSample(),
		void particleSet(),
		void sampleInScope();
		void L();
		void maxDisplacement();
		void energySolid();
		void seed();
