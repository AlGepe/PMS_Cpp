class R3 {
	private:

		double _x,
					 _y,
					 _z;

	public :
	
		// Getters
		double x();
		double y();
		double z();
		
		//Setters
		void x(double newX);
		void y(double newY);
		void z(double newZ);

		//Copy
		R3 (R3& sourceObject);
		// Copy Constructor
		R3 (double x = .0, double y = .0, double z = .0);

		// Operators
		R3 operator + (R3 toAdd);
		R3 operator += (R3 toAdd);
		R3 operator - (R3 toSubstract);
		R3 operator -= (R3 toSubstract);
}
