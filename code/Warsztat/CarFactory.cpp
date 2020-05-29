#include <list>
#include "CarFactory.h"
#include "UI.h"
#include <iostream>

using namespace std;

CarElement CarFactory::createCarElement() {
	
	char a = 'N';
	list<CarElement> elements;
	string name = ui->askForString("Podaj nazwe elementu:");
	a = ui->askForChar("Stworzyc podelement ? T/N");
	while (a == 't' || a == 'T') {
		elements.push_back(createCarElement());
		a = ui->askForChar("Stworzyc podelement ? T/N");
	}
	list<Part> parts;
	bool addNext = true;
	while (addNext) {
		addNext = false;
		string part_name;
		part_name = ui->askForString(" Podaj nazwe czesci ? [0 - wyjscie]");
		if (part_name.length() > 1) {
			Part part(part_name);
			parts.push_back(part);
			addNext = true;
		}
	}
	CarElement cElement(name, elements, parts);
	return cElement;
}

CarFactory::CarFactory(UI* _ui):ui(_ui)
{
}

CarFactory::~CarFactory()
{
}

Car* CarFactory::buildCar(Client* client, string* carElements, int cElements_size)
{
	list<CarElement> elements;
	//build carElements from string
	for (int i = 0; i < cElements_size; i++) {
		//Create car element from string
	}
	//
	Car* car = new Car(client, elements);
	return car;
}

Car* CarFactory::buildCar(Client* client) {
	char a = 'T';
	list<CarElement> elements;
	while (a == 't' || a == 'T') {
		elements.push_back(createCarElement());
		a = ui->askForChar(" Stworzyc nastepny element ? T/N");
	}
	Car* car = new Car(client, elements);
	return car;
}
