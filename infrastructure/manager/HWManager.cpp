#include "HWManager.h"

 bool HWManager::getSensorConfigration(uint32 numberOfSensors,
		 const uint32* addresses, std::list<Sensor>& configurationToPopulate)
{
	bool status = false;
	if(addresses != 0 && numberOfSensors > 0)
	{
		for(uint32 x = 0;x<numberOfSensors; x++)
		{
			status = checkAddress(addresses[x]);
			if(status)
			{
				Sensor newSensor(addresses[x]);
				//Default to linear trends for now
				LinearTrend lt;
				newSensor.setTrend(lt);
				newSensor.setTrendFunc(LinearTrend::linearTrend);

				uint32 val = newSensor.read();
				val = newSensor.read();

				HWManager::allSensors.insert(std::pair<uint32, Sensor>(addresses[x],newSensor));
				configurationToPopulate.push_back(newSensor);
			}
		}
	}
	return status;
}

 bool HWManager::getChannelConfigration(uint32 numberOfOutputs,
			const uint32* addresses, std::list<Channel>& configurationToPopulate)
 {
	bool status = false;
	if(addresses != 0 && numberOfOutputs > 0)
	{
		for(uint32 x = 0;x<numberOfOutputs; x++)
		{
			status = checkAddress(addresses[x]);
			if(status)
			{
				Channel newChannel;
				HWManager::allChannels.insert(std::pair<uint32, Channel>(addresses[x],newChannel));
				configurationToPopulate.push_back(newChannel);
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

	std::map<uint32,Sensor>::iterator it;
	it = allSensors.find(requestedAddress);

	if(it == HWManager::allSensors.end()) // It was not found
	{
		status = true;
	}
	return status;
}


bool HWManager::checkChannels(uint32 requestedAddress)
{
	bool status = false;

	std::map<uint32,Channel>::iterator it;
	it = allChannels.find(requestedAddress);

	if(it == HWManager::allChannels.end()) // It was not found
	{
		status = true;
	}
	return status;
}

//Definition of the static variable
std::map<uint32, Sensor> HWManager::allSensors;
std::map<uint32, Channel> HWManager::allChannels;
