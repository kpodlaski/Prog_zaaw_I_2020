#include "System.h"
#include <stdexcept>
#include "PersonClient.h"
#include "CompanyClient.h"

void System::repairFinished(Order* order)
{
	//TODO
	throw std::runtime_error("Not implemented yet");
}

Client* System::new_personclient()
{
	string name = ui->askForString("Client Name");
	string sname = ui->askForString("Client Surname");
	string phone = ui->askForString("Client Phone");
	string address = ui->askForString("Client Address");
	return new_personclient(name, sname, phone, address);
}

Client* System::new_personclient(string name, string sname, string phone, string address)
{
	Client* client = (Client*) new PersonClient("John", "Doe", "+000000", "ABC");
	data_provider->addClient(client);
	return (Client *) client;
}

Client* System::new_companyclient()
{
	Client* client = (Client*) new CompanyClient();
	data_provider->addClient(client);
	return (Client*)client;
}

Car* System::new_car(Client* client)
{
	Car* c = carFactory->buildCar(client);
	//If we have a car we can have an Order
	data_provider->addCar(c);
	return c;
}

void System::survey_next_client(Employee* employee)
{
	Client* client = data_provider->getNextWaitingClient();
	Order* order = employee->survey_client(client);
	data_provider->addToDiagnose(order);
}

void System::diagnose_next(Mechanic* mechanic)
{
	Order* order = data_provider->getNextToDiagnose();
	list<Repair*> repairs = mechanic->diagnose(order);
	order->repair.splice(order->repair.end(), repairs);
	data_provider->addToRepair(order);
}

void System::repair_next_car(Mechanic* mechanic)
{
	Order* order = data_provider->getNextToRepair();
	mechanic->do_repair(order);
	data_provider->moveToRepaired(order);
}

void System::client_pickup_car(Client* client)
{
	bool _continue;
	do {
		
		Car* car = data_provider->getRepairedCarForClient(client);
		_continue = (car == 0);
		if (_continue) {
			ui->showInfo("Klient " + client->desc() + " odbiera auto " + car->info());
			data_provider->destroy_car(car);
		}
		else {
			ui->showInfo("Nie ma samochodow dla klienta " + client->desc());
		}
	}
	while (_continue);
}

Employee* System::new_employee(string name, string sname, string phone, string address, string account)
{
	Employee* employee = new Employee(name, sname, phone, address, account, this, ui);
	data_provider->addEmployee(employee);
	return employee;
}

Mechanic* System::new_mechanic(string name, string sname, string phone, string address, string account)
{
	Mechanic* mechanic = new Mechanic(name, sname, phone, address, account, this, ui);
	data_provider->addMechanic(mechanic);
	return mechanic;
}

System::System(UI* _ui, DataProvider* dp): carFactory(new CarFactory(_ui)), data_provider(dp), ui(_ui)
{
}


System::~System()
{
}

