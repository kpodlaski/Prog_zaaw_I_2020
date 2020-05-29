#include "Order.h"
#include "Employee.h"


Order::Order(Car* _car) : car_to_repair(_car)
{
	_car->owner->orders.push_back(this);
}

void Order::start_diagnose(Mechanic* mechanic, list<Repair*> repairs) {
	car_to_repair->start_diagnose(mechanic, repairs);
}