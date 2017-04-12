#ifndef SOLID_H
#define SOLID_H
#include <vector>
#include "Data.h"
#include "EnergyValue.h"
#include "Particle.h"
#include "LennarJones.h"

class Solid{
	private: 
		Data * simData;
		int _numParticles,
				_seed,
				_numbRecalcNeigh;
		std::vector<Particle> _particleSample,
										 _particleSet,
										 _sampleInScope;
		double _L,
					 _maxDisplacement;
		EnergyValue _energySolid;
			
	public:
		//Constructor
		Solid();

		void Init();
		double ranf();
		double gauss();
		void calculateNeighbours();
		void takeSample();
		double bring2solid();
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
		
		//setters
		void numParticles(int newNumb);
		void numbRecalcNeigh(int newRecalc);
		void particleSample(std::vector<Particle> newSample);
		void particleSet(std::vector<Particle> newSet);
		void sampleInScope(std::vector<Particle> newSample);
		void L(double newL);
		void maxDisplacement(int newMaxDisp);
		void energySolid(EnergyValue newEnergy);
		void seed(int newSeed);
};
#endif
