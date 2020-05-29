#ifndef CARELEMENT_H
#define CARELEMENT_H
#include <list>
#include <string>
#include "CarElement.h"
#include "Part.h"
#include "Repair.h"

using namespace std;

class Part;
class Mechanic;
class Repair;

class CarElement
{
private:
	list<CarElement> subelement;
	list<Part> parts;
	string name;
public:
	CarElement(string _name, list<CarElement> _subelement, list<Part> _parts);
	virtual ~CarElement();
	void start_diagnose(Mechanic* mechanic, list<Repair*> repairs);
	string desc();


friend class Mechanic;

};

#endif

