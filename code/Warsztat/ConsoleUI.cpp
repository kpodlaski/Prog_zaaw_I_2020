#include <iostream>
#include <string>
#include "ConsoleUI.h"

using namespace std;

ConsoleUI::ConsoleUI()
{
}

ConsoleUI::~ConsoleUI()
{
}

void ConsoleUI::showInfo(string msg)
{
	cout << msg << endl;
}

char ConsoleUI::askForChar(string msg)
{
	showInfo(msg);
	char c;
	cin >> c;
	return c;
}

string ConsoleUI::askForString(string msg)
{
	showInfo(msg);
	string s;
	cin >> s;
	return s;
}
