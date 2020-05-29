#include "UIWithLogger.h"

UIWIthLogger::UIWIthLogger(UI* _ui) : ui(_ui) {
}

void UIWIthLogger::showInfo(string msg) {
	//file fout;
	//log message
	// fout<<msg;
	ui->showInfo(msg);
}

char UIWIthLogger::askForChar(string msg)
{
	return ui->askForChar(msg);
}

string UIWIthLogger::askForString(string msg)
{
	return ui->askForString(msg);
}

