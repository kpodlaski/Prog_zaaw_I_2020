#include "Person.h"

Person::Person(string name, string sname, string phone, string address): _name(name), _sname(sname), _phone(phone), _address(address)
{
}

string Person::name()
{
	return _name;
}

string Person::sname()
{
	return _sname;
}

string Person::phone()
{
	return _phone;
}

string Person::address()
{
	return _address;
}
