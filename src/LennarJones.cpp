#include <LennarJones.h>

LennarJones::LennarJones()
{
	data = vector<R2>;
}

void LennarJones::saveInList(double distance, double potential)
{
	data.push_back(R2 test(distance, potential));
}
