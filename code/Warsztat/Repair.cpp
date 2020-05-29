#include "Repair.h"

Repair::Repair(CarElement* _elemnet, string _comment, list<Part*> _fault_parts): element(_elemnet), comment(_comment), state(false), fault_parts(_fault_parts)
{
}

void Repair::add_fault_part(Part* p)
{
	fault_parts.push_back(p);
}

int Repair::no_of_faults()
{
	return fault_parts.size();
}
