#include <R2.h>
#include <string>

class LennarJones
{
	private:
		deque<R2> data;
		
	public:
		LennarJones();
		void saveInList(double distance, double potential);
		void printToFile(String fileName);
