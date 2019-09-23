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


Interface::Interface(): virtualPlatform(0)
{
}


std::map<uint32, uint32> Interface::getSensorOutput()
{
	if(virtualPlatform != 0)
	{
		return virtualPlatform->getSensorOutput();
	}
	return std::map<uint32, uint32>();
}

std::map<uint32, uint32> Interface::getChannelOutput()
{
	std::map<uint32, uint32> channel;
	if(virtualPlatform != 0)
	{
		std::map<uint32, uint32> rawSensor = virtualPlatform->getSensorOutput();

		//TODO better dynamic sensor consolidation and abstraction
		if(MercuryOutputConfig::NUMBER_OF_CHANNELS == 1)
		{

			uint32 channelValue = 0;
			std::map<uint32, uint32>::iterator it = rawSensor.begin();
			while (it != rawSensor.end())
			{
				channelValue += it->second;
				it++;
			}
			channel[MercuryOutputConfig::CHANNEL_1_ADDRESS] = channelValue/rawSensor.size();
		}
	}
	return channel;
}

void Interface::zeroSensors()
{
	bool status = false;
	if(virtualPlatform != 0)
	{
		virtualPlatform->zeroSensors();
	}
}

/**
 * /brief the registerPlatform allows for a new platform to be registered
 */
bool Interface::registerPlatform(VirtualPlatform* newVirtualPlatform)
{
	bool status = false;
	if(newVirtualPlatform != 0)
	{
		virtualPlatform = newVirtualPlatform;
		status = true;
	}
	else
	{
		Logger::log("Interface passed 0 pointer");
	}
	return status;
}

//Definition of the static variables
Interface* Interface::instance = 0;
