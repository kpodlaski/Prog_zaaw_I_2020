#include "CarFactory.h"
#include "PersonClient.h"
#include "UI.h"
#include "UIWithLogger.h"
#include "ConsoleUI.h"
#include "InvoiceBuilder.h"
#include "System.h"

using namespace std;

int main() {

	UIWIthLogger* ui = new UIWIthLogger( (UI*) new ConsoleUI());
	DataProvider* dp = new RAMDataProvider();
	System * workshop = new System( (UI*) ui, (DataProvider*) dp);
	Client* client = workshop->new_personclient();
	Mechanic* m = workshop->new_mechanic("Ela", "Ela", "+11111", "CBC", "PL123");
	string* carElements = new string[2]{ "Silnik: uszczelka, pokrywa, tlok, tlok, tlok", 
		"Naped przod: os, wachacz_l, wachacz_p; Beben_l: tarcza, hamulec, kolo; Beben_p: tarcza, hamulec, kolo;" };
	//add ui to mechanic
	workshop->survey_next_client((Employee*) m);
	//Diagnose Car
	workshop->diagnose_next(m);
	//When diagnose finished do repairs
	workshop->repair_next_car(m);
	workshop->client_pickup_car(client);
}