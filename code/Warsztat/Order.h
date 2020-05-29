#ifndef ORDER_H
#define ORDER_H

#include <list>
#include "Car.h"
#include "Repair.h"
#include "Employee.h"
#include "System.h"


using namespace std;

class Car;
class Mechanic;

class Order
{
private:
	Car* car_to_repair;
	list<Repair*> repair;

public:
	Order(Car*);
	void start_diagnose(Mechanic*, list<Repair*>);

friend class System;
};

#endif // !ORDER_H

