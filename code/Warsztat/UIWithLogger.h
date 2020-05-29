#ifndef UIWITHLOGGER_H
#define UIWITHLOGGER_H

#include "UI.h"


class UIWIthLogger : UI {
private:
	UI* ui;

public:
	UIWIthLogger(UI* _ui);
	virtual void showInfo(string msg);
	virtual char askForChar(string msg);
	virtual string askForString(string msg);
};

#endif // !UIWITHLOGGER_H
