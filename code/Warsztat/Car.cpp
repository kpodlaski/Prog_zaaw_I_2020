#include <list>
#include <string>
#include "Car.h"
#include "Repair.h"

using namespace std;

Car::~Car()
{
}

Car::Car(Client* _owner, string info, list<CarElement> _elements): owner(_owner), _info(info), element(_elements)
{
	owner->cars.push_back(this);
}

void Car::start_diagnose(Mechanic* mechanic, list<Repair*> repairs) {
	for (std::list<CarElement>::iterator it = this->element.begin(); it != this->element.end(); ++it)
		it->start_diagnose(mechanic, repairs);
}

string Car::info()
{
	return _info;
}
