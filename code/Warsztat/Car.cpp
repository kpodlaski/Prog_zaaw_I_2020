#include <list>
#include "Car.h"
#include "Repair.h"

using namespace std;

Car::~Car()
{
}

Car::Car(Client* _owner, list<CarElement> _elements): owner(_owner), element(_elements)
{
	owner->cars.push_back(this);
}

void Car::start_diagnose(Mechanic* mechanic, list<Repair*> repairs) {
	for (std::list<CarElement>::iterator it = this->element.begin(); it != this->element.end(); ++it)
		it->start_diagnose(mechanic, repairs);
}
