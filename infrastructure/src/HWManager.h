#ifndef _HW_MANAGER_H_
#define _HW_MANAGER_H_

#include "../../common/CommonTypes.h"
#include "../../common/Logger.h"
#include <sstream>

#include <algorithm>
#include <list>

class HWManager
{

public:
	static bool getSensorConfigration(uint32 numberOfSensors, const uint32* addresses, std::list<uint32>& configurationToPopulate);

private:
	static std::list<uint32> usedSensorAddresses;
	static bool useSensorAddress(uint32 requestedSensorAddress);
};

#endif
