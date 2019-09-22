#include "Interface.h"

Interface* Interface::getInstance()
{
	if(instance == 0)
	{
		static Interface self;
		instance = &self;
	}
	return instance;
}


Interface::Interface():activeConfiguration(std::list<uint32>()), oc(MercuryCommon::OutputContainer())
{
}

/*
 * initialize the interface
 */
void Interface::initialize()
{
	bool status = false;
	status = HWManager::getSensorConfigration(MercuryInputConfig::NUMBER_OF_ACCELEROMETERS,
			MercuryInputConfig::ALL_ACCELEROMETERS,
			activeConfiguration);
	if(!status)
	{
		Logger::log("Error initializing Interface infrastructure");
		exit;
	}
}


//Definition of the static variables
Interface* Interface::instance = 0;


