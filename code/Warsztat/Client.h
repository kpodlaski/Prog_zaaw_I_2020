#ifndef  CLIENT_H
#define CLIENT_H

#include <string>
#include <list>
#include "Car.h"
#include "Order.h"

using namespace std;

class Car;
class Order;

class Client
{
private:
	string taxid;
	list<Car*> cars;
	list<Order*> orders;
public:
	Client();
	~Client();

	virtual string desc();
	virtual string phone();
	virtual string address();

friend class Order;
friend class Car;


};

#endif 

