#ifndef  UI_H
#define UI_H

#include <string>
using namespace std;

class UI
{
public:
	virtual void showInfo(string msg) =0;
	virtual char askForChar(string msg) =0;
	virtual string askForString(string msg) =0;

};

#endif // ! UI_H




