#include <R3>
#include <vector>

class Particle
{
	private:
		R3 * _position;
		R3 * _velocity;
		R3 * _acceleration;

		std::vector<Particle> vecinity;

	// Maybe needs a copy constructor? or copy method? TBD
	
	public:
		Particle();
		//setters
		void position(R3 newPos);
		void velocity(R3 newVel);
		void acceleration(R3 newAcc);
		void vecinity(vector<Particle> newNeighbours);
		void clearVecinity();
		/* Not sure if needed
		void position(double posX, double posY,double posZ);
		void velocity(double velX, double velY,double velZ);
		void acceleration(double accX, double accY,double accZ);
		*/
		//Getters
		R3 * position();
		R3 * velocity();
		R3 * acceleration();
		std::vector<Particle> vecinity();

