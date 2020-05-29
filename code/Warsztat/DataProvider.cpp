#include "DataProvider.h"

void RAMDataProvider::addClient(Client* c)
{
	waiting_clients.push_back(c);
}

void RAMDataProvider::addCar(Car* car)
{
	waiting_cars.push_back(car);
}

void RAMDataProvider::addEmployee(Employee* employee)
{
	employees.push_back(employee);
}

void RAMDataProvider::addMechanic(Mechanic* mechanic)
{
	mechanics.push_back(mechanic);
}

void RAMDataProvider::addToDiagnose(Order* order)
{
	waiting_to_diagnose.push_back(order);
}

void RAMDataProvider::addToRepair(Order * order)
{
	waiting_to_repair.push_back(order);
}

void RAMDataProvider::moveToRepaired(Order* order)
{
	repaired.push_back(order);
}

Car* RAMDataProvider::getRepairedCarForClient(Client* client)
{
	return nullptr;
}

Client* RAMDataProvider::getNextWaitingClient()
{
	Client* c = waiting_clients.front();
	if (c != 0) waiting_clients.pop_front();
	return c;
}

Order* RAMDataProvider::getNextToDiagnose()
{
	Order* o = waiting_to_diagnose.front();
	if (o != 0) waiting_to_diagnose.pop_front();
	return o;
}

Order* RAMDataProvider::getNextToRepair()
{
	Order* o = waiting_to_repair.front();
	if (o != 0) waiting_to_repair.pop_front();
	return o;
}

void RAMDataProvider::destroy_car(Car* car)
{
	//Remove from all lists the car can still exist
	//Remove car from client 
	//Remove all orders and repairs
	//Destroy pointer
}
