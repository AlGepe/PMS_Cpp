#include <vector>

class Solid{
	private: 
		int numParticles;
		int numbRecalcNeigh;
		vector<Particle> particleSample,
										 particleSet,
										 sampleInScope;
		double L;
		double maxDisplacement;
		EnergyValue energySolid;
		int seed;
			
	public:
		//Constructor
		Solid();
		Init();
		ranf();
		gauss();
		calculateNeighbours();
		takeSample();
		bind();
		nexStep();
		lennardJonesValues();
		//setters
		int numParticles();
		int numbRecalcNeigh();
		vector<Particle> particleSample(),
		vector<Particle> particleSet(),
		vector<Particle> sampleInScope();
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
