#include "LennarJones.h"

LennarJones::LennarJones()
{
	//data = std::deque<R2>;
}

void LennarJones::saveInList(double distance, double potential)
{ 
	R2 test(distance, potential);
	data.push_back(test);
}
