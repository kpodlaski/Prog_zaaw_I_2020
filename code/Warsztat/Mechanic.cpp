#include "Employee.h"
#include "Part.h"
#include "InvoiceBuilder.h"
#include <iostream>
#include <list>


using namespace std;

list<Repair*> Mechanic::diagnose(Order* order) {
	list<Repair*> repairs;
	order->start_diagnose(this, repairs);
	
	return repairs;

}

void Mechanic::diagnose(CarElement* cElement, list<Repair*> repairs) {
	char a;
	ui->showInfo(" Sprawdz element samochodu: ");
	ui->showInfo(cElement->desc());
	list<Part*> parts;
	for (std::list<Part>::iterator it = cElement->parts.begin(); it != cElement->parts.end(); ++it) {
		Part part = *it;
		a = ui->askForChar("Czesc : " + part.name + " Czy Naprawic ? T/N");
		if (a == 'T')
		{
			parts.push_back(&part);
		}
	}
	
	if (parts.size() > 0) {
		string comment = ui->askForString("Opis usterki");
		//iterate over cElement Partrs
		Repair* r = new Repair(cElement, comment, parts);
		repairs.push_back(r);
	}

	
}

void Mechanic::do_repair(Order* order)
{
	for (std::list< InvoiceBuilder*>::iterator it = this->invBulders.begin(); it != invBulders.end(); ++it) {
		(*it)->repairFinished(order);
	}

}

void Mechanic::observer_register(InvoiceBuilder* iBuilder)
{
}

Mechanic::Mechanic(string _name, string _sname, string _phone, string _address, string _account, System * _workshop, UI* _ui):
	Employee(_name, _sname, _phone,_address,_account, _workshop, _ui)
{
}
