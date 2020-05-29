#ifndef REPAIR_H
#define REPAIR_H

#include <list>
#include "Part.h"
#include "CarElement.h"


using namespace std;

class Part;
class CarElement;

class Repair
{
private:
	list<Part*> repaired_part;
	CarElement* element;
	list<Part*> fault_parts;
	bool state;
	string comment;

public:
	Repair(CarElement*, string, list<Part*>);
	void add_fault_part(Part*);
	int no_of_faults();
};

#endif // !REPAIR_H
