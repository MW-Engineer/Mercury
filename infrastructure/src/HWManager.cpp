#include "HWManager.h"

 bool HWManager::getSensorConfigration(uint32 numberOfSensors, const uint32* addresses, std::list<uint32>& configuration)
{
	bool status = false;
	if(addresses != 0 && numberOfSensors > 0)
	{
		status = true;
		for(uint32 x = 0;x<numberOfSensors; x++)
		{
			status = status && useSensorAddress(addresses[x]);
		}
	}
	return status;
}

bool HWManager::useSensorAddress(uint32 requestedSensorAddress)
{
	bool status = false;
	HWManager::usedSensorAddresses.push_front(requestedSensorAddress);
	std::list<uint32>::iterator it = std::find(HWManager::usedSensorAddresses.begin(),
			HWManager::usedSensorAddresses.end(),
			requestedSensorAddress);
	if(it != HWManager::usedSensorAddresses.end())
	{
		HWManager::usedSensorAddresses.push_front(requestedSensorAddress);
		status = true;
	}
	else
	{
		 std::stringstream ss;
		    ss <<"Bad Address: "<< std::hex << requestedSensorAddress;
		Logger::log(ss.str());
	}
	return status;
}

//Definition of the static variable
std::list<uint32> HWManager::usedSensorAddresses;
