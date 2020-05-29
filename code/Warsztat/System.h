#ifndef SYSTEM_H
#define SYSTEM_H
#include "InvoiceBuilder.h"
#include "DataProvider.h"
#include "Order.h"
#include "CarFactory.h"
#include "UI.h"
#include "Repair.h"

class InvoiceBuilder;
class CarFactory;
class UI;
class Car;
class Client;
class Order;
class Employee;
class Mechanic;
class DataProvider;
class Repair;



class System : public InvoiceBuilder
{
public:
	System(UI *, DataProvider *);
	~System();
	CarFactory * carFactory;
	virtual void repairFinished(Order* order) override;
	Client* new_personclient(string name, string sname, string phone, string address);
	Client* new_personclient();
	Client* new_companyclient();
	Employee* new_employee(string name, string sname, string phone, string address, string account);
	Mechanic* new_mechanic(string name, string sname, string phone, string address, string account);
	Car* new_car(Client* client);
	void survey_next_client(Employee* employee);
	void diagnose_next(Mechanic* mechanic);
	void repair_next_car(Mechanic* mechanic);
	


private:
	DataProvider* data_provider;
	UI* ui;
};

#endif
