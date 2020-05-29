#ifndef  ORDER_H
#define ORDER_H

#include "Order.h"
#include <list>

using namespace std;

class Order;

class Invoice
{
private:
	list<Order*> order;
};

#endif // ! ORDER_H
