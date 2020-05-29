#ifndef INVIOCEBUILDER_H
#define INVIOCEBUILDER_H
#include "Order.h"

class Order;

class InvoiceBuilder
{
public:
	virtual void repairFinished(Order* order) = 0;
	
};


#endif // !INVIOCEBUILDER_H
