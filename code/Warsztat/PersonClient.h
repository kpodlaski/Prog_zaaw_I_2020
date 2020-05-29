#ifndef  PERSONCLIENT_H
#define PERSONCLIENT_H

#include "Person.h"
#include "Client.h"


class PersonClient :
	protected Person, Client
{
public:
	PersonClient(string _name, string _sname, string _phone, string _address);
};

#endif // ! PERSONCLIENT_H
