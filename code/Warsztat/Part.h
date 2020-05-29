#ifndef PART_H
#define PART_H

#include <string>
#include "Employee.h"

using namespace std;

class Part
{
private:
	string name;
	double price;

public:
	Part(string _name, double _price);

public:
	Part(string _name);

friend class Mechanic;
};

#endif // !PART_H
