#ifndef CAR_H
#define CAR_H
#include <list>
#include <string>
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
	string _info;
public:
	Car(Client*, string, list < CarElement>);
	void start_diagnose(Mechanic*, list<Repair*>);
	string info();
	virtual ~Car();

friend class Order;
};
#endif

