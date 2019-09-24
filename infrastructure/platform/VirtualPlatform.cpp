#include "VirtualPlatform.h"

VirtualPlatform::VirtualPlatform():activeSensors(std::list<Sensor*>()),activeChannels(std::list<Channel*>())
{
}

VirtualPlatform::~VirtualPlatform()
{

}

VirtualPlatform* VirtualPlatform::getPlatform()
{
	if(instance == 0)
	{
		static VirtualPlatform self;
		instance = &self;
	}
	return instance;
}

std::map<uint32, uint32> VirtualPlatform::getSensorOutput()
{
	std::map<uint32, uint32> sensorValues;

	for (std::list<Sensor*>::iterator it = activeSensors.begin(); it != activeSensors.end(); it++)
	{
		sensorValues[(*it)->getAddress()] = (*it)->read();
	}
	return sensorValues;
}

void VirtualPlatform::zeroSensors()
{
	for (std::list<Sensor*>::iterator it = activeSensors.begin(); it != activeSensors.end(); it++)
	{
		(*it)->setReadValue(0);
	}
}

/*
 * initialize the Virtual Platform
 */
bool VirtualPlatform::initialize()
{
	bool status = false;
	status = HWManager::getInstance()->getSensorConfigration(
			MercuryInputConfig::NUMBER_OF_ACCELEROMETERS,
			MercuryInputConfig::ALL_ACCELEROMETERS,
			activeSensors);

	if(!status)
	{
		Logger::log("Error Initializing Sensors in the Virtual Platform");
	}
	else
	{
		status = HWManager::getInstance()->getChannelConfigration(MercuryOutputConfig::NUMBER_OF_CHANNELS,
				MercuryOutputConfig::ALL_CHANNELS,
				activeChannels);

		if(!status)
		{
			Logger::log("Error initializing the channels in the Virtual Platform");
		}
	}
	return status;
}

//Definition of static
VirtualPlatform* VirtualPlatform::instance = 0;
