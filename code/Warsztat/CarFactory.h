#ifndef CARFACTORY_H
#define CARFACTORY_H
#include <string>
#include "Car.h"
#include "Client.h"
#include "UI.h"
#include "CarElement.h"


class Client;
class Car;
class CarElement;

class CarFactory
{
private:
	UI* ui;
	CarElement createCarElement();
public:
	CarFactory(UI*);
	~CarFactory();
	//create car on base of a string description
	Car* buildCar(Client* client, string* carElements, int cElemnts_size);
	//create car on base of Q&A with user cout/cin;
	Car* buildCar(Client* client);
};

#endif
