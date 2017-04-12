#ifndef ENERGYVALUE_H
#define ENERGYVALUE_H
#endif
class EnergyValue
{
	private:
		double _u,
					 _k;
	public:
		EnergyValue(double u = .0, double k = .0);
		void u(double newU);
		void k(double newK);
		double u();
		double k();
};
