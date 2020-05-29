#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Person.h"
#include "Client.h"
#include "Order.h"
#include "Employee.h"
#include "System.h"
#include "Repair.h"
#include "UI.h"

using namespace std;

class Order;
class Client;
class Repair;
class CarElement;
class InvoiceBuilder;
class System;
class UI;

class Employee : Person
{
protected:
	string account;
	System * workshop;
	UI* ui;
public:
	Employee(string _name, string _sname, string _phone, string _address, string _account, System * _workshop, UI* _ui);
	Order* survey_client(Client* client);
};

class Mechanic : Employee
{
public:
	list<Repair*> diagnose(Order* order);
	void diagnose(CarElement* cElement, list<Repair*> repairs);
	void do_repair(Order* order);
	void observer_register(InvoiceBuilder* iBuilder);
	Mechanic(string _name, string _sname, string _phone, string _address, string _account, System * _workshop, UI* _ui);

private:

	list< InvoiceBuilder*> invBulders;

};

#endif




