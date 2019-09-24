#ifndef MERCURY_TESTBED_H_
#define MERCURY_TESTBED_H_
#include "../interface/Interface.h"
#include "../infrastructure/platform/VirtualPlatform.h"
#include "../common/Logger.h"

#include "MenuConfiguration.h"


class MercuryTestbed
{
public:
	static void StartTetbed();

	//Initalize testbed
	static bool intializeComponents();

	//Helper Terminal Methods
	static uint8 validateInput(std::string input);
	static void displayMenu();
	static void displayAllData(std::map<uint32,uint32> valMap);


private:
	static bool isStarted;



};

#endif
