#include "Employee.h"
#include "System.h"



Employee::Employee(string _name, string _sname, string _phone, string _address, string _account, System * _workshop, UI* _ui) : Person(_name,_sname,_phone,_address), account(_account), workshop(_workshop), ui(_ui)
{
}

Order* Employee::survey_client(Client* client)
{
	//TODO DO survey
	Car* car = workshop->new_car(client);
	Order* order = new Order(car);
	return order;
}
