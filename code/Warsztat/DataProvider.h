#ifndef  DATAPROVIDER_H
#define DATAPROVIDER_H
#include <list>
#include "Client.h"
#include "Car.h"
#include "Employee.h"

class Client;
class Car;
class Employee;
class Mechanic;

class DataProvider
{
public:
	virtual void addClient(Client*) =0 ;
	virtual void addCar(Car*) = 0;
	virtual void addEmployee(Employee* employee) = 0;
	virtual void addMechanic(Mechanic* employee) = 0;
	virtual void addToDiagnose(Order* order) = 0;
	virtual void addToRepair(Order* order) = 0;
	virtual void moveToRepaired(Order* order)=0;

	virtual Client* getNextWaitingClient() = 0;
	virtual Order* getNextToDiagnose() = 0;
	virtual Order* getNextToRepair() = 0;
	virtual Car* getRepairedCarForClient(Client* client)=0;
	virtual void destroy_car(Car* car)=0;
};



class RAMDataProvider : public DataProvider
{
private:
	list<Client*> waiting_clients;
	list<Car*> waiting_cars;
	list<Order*> waiting_to_diagnose;
	list<Order*> waiting_to_repair;
	list<Order*> repaired;
	list<Employee*> employees;
	list<Mechanic*> mechanics;

public:
	virtual void addClient(Client *);
	virtual void addCar(Car*);
	virtual void addEmployee(Employee* employee);
	virtual void addMechanic(Mechanic* employee);
	virtual void addToDiagnose(Order* order);
	virtual void addToRepair(Order * order);
	virtual void moveToRepaired(Order* order);

	virtual Car* getRepairedCarForClient(Client* client);
	virtual Client * getNextWaitingClient();
	virtual Order* getNextToDiagnose();
	virtual Order* getNextToRepair();

	virtual void destroy_car(Car* car);
	
};

#endif // ! DATAPROVIDER_H
