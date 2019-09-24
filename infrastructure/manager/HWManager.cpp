#include "HWManager.h"

HWManager* HWManager::getInstance()
{
	if(instance == 0)
	{
		static HWManager self;
		instance = &self;
	}
	return instance;
}


HWManager::HWManager(): allSensors(std::map<uint32, Sensor*>()) ,allChannels(std::map<uint32, Channel*>())
{

}

HWManager::~HWManager()
{
	for(std::map<uint32, Sensor*>::iterator it = allSensors.begin();it != allSensors.end();it++)
	{
		delete it->second;
	}
	for(std::map<uint32, Channel*>::iterator it = allChannels.begin();it != allChannels.end();it++)
	{
		delete it->second;
	}

}

 bool HWManager::getSensorConfigration(uint32 numberOfSensors,
		 const uint32* addresses, std::list<Sensor* >& configurationToPopulate)
{
	bool status = false;
	if(addresses != 0 && numberOfSensors > 0)
	{
		for(uint32 x = 0;x<numberOfSensors; x++)
		{
			status = checkAddress(addresses[x]);
			if(status)
			{
				//Default to linear trends for now
				allSensors[addresses[x]] = new Sensor(addresses[x]);
				allSensors[addresses[x]]->setTrendFunc(Trends::preformLinearTrend);

				configurationToPopulate.push_back(allSensors[addresses[x]]);
			}
		}
	}
	return status;
}

 bool HWManager::getChannelConfigration(uint32 numberOfOutputs,
			const uint32* addresses, std::list<Channel*>& configurationToPopulate)
 {
	bool status = false;
	if(addresses != 0 && numberOfOutputs > 0)
	{
		for(uint32 x = 0;x<numberOfOutputs; x++)
		{
			status = checkAddress(addresses[x]);
			if(status)
			{
				allChannels[addresses[x]] = new Channel(addresses[x]);
				configurationToPopulate.push_back(allChannels[addresses[x]]);
			}
		}
	}
	return status;
}

bool HWManager::checkAddress(uint32 requestedAddress)
{
	bool status = false;
	status = HWManager::checkSensors(requestedAddress);
	if(!status)
	{
		 std::stringstream ss;
		    ss <<"Address already in use as a Sensor: 0x"<< std::hex << requestedAddress;
		Logger::log(ss.str());
	}
	else
	{
		status = HWManager::checkChannels(requestedAddress);
		if(!status)
		{
			 std::stringstream ss;
				ss <<"Address already in use as a Channel: 0x"<< std::hex << requestedAddress;
			Logger::log(ss.str());
		}
	}
	return status;
}

bool HWManager::checkSensors(uint32 requestedAddress)
{
	bool status = false;

	std::map<uint32,Sensor*>::iterator it;
	it = allSensors.find(requestedAddress);

	if(it == allSensors.end()) // It was not found
	{
		status = true;
	}
	return status;
}


bool HWManager::checkChannels(uint32 requestedAddress)
{
	bool status = false;

	std::map<uint32,Channel*>::iterator it;
	it = allChannels.find(requestedAddress);

	if(it == allChannels.end()) // It was not found
	{
		status = true;
	}
	return status;
}

HWManager* HWManager::instance = 0;
