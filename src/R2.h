#ifndef R2_H
#define R2_H
#endif
class R2
{
	private:
		double _x,
					 _y;
	public:
		R2(double x = .0, double y = .0);
		double x();
		double y();
		void x(double newX);
		void y(double newY);
};
