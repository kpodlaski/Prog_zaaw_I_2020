#ifndef CAR_H
#define CAR_H
#include <list>
#include "Client.h"
#include "CarElement.h"
#include "Employee.h"
#include "Repair.h"

using namespace std;
class Client;
class Mechanic;

class Car
{
private:
	Client* owner;
	list<CarElement> element;
public:
	Car(Client*, list < CarElement>);
	void start_diagnose(Mechanic*, list<Repair*>);
	virtual ~Car();

friend class Order;
};
#endif

