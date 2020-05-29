#ifndef PERSON_H
#define PERSON_H

#include <string>


using namespace std;

class Person
{
private:
	string _name;
	string _sname;
	string _phone;
	string _address;
public:
	Person(string name, string sname, string phone, string address);
	string name();
	string sname();
	string phone();
	string address();
};

#endif // !PERSON_H
