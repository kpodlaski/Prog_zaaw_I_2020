#include <list>
#include "CarElement.h"
#include "Repair.h"

using namespace std;

CarElement::CarElement(string _name, list<CarElement> _subelement, list<Part> _parts): name(_name), subelement(_subelement), parts(_parts){
}

CarElement::~CarElement()
{
}

void CarElement::start_diagnose(Mechanic* mechanic, list<Repair*> repairs) {
	for (std::list<CarElement>::iterator it = this->subelement.begin(); it != this->subelement.end(); ++it)
		it->start_diagnose(mechanic, repairs);
	mechanic->diagnose(this, repairs);
}

string CarElement::desc()
{
	return name;
}
