#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "UI.h"


class ConsoleUI : UI {
public:
	ConsoleUI();
	~ConsoleUI();
	virtual void showInfo(string msg);
	virtual char askForChar(string msg);
	virtual string askForString(string msg);
};

#endif // !CONSOLEUI_H
