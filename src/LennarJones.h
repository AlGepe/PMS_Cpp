#ifndef LENNARDJONES_H
#define LENNARDJONES_H
#include <R2.h>
#include <string>
#include <deque>

class LennarJones
{
	private:
		std::deque<R2> data;
		
	public:
		LennarJones();
		void saveInList(double distance, double potential);
		void printToFile(std::string fileName);
	};
#endif
