#ifndef _HW_MANAGER_H_
#define _HW_MANAGER_H_

#include "../../common/CommonTypes.h"

#include "../input/devices/Sensor.h"
#include "../input/trend/LinearTrend.h"

#include "../output/Channel.h"

#include "../../common/Logger.h"
#include <sstream>

#include <algorithm>
#include <list>
#include <map>

/**
 * \class HWManager
 * \brief HWManager allocates addresses and verifies that already allocated addresses are not going to be reallocated.
 *
 *	Additionally, responsible for issuing Channel(Output) and Sensor(Input) data objects
 *
 *
 */
class HWManager
{

public:
	static bool getSensorConfigration(uint32 numberOfSensors,
			const uint32* addresses,
			std::list<Sensor>& configurationToPopulate);
	static bool getChannelConfigration(uint32 numberOfSOutputs,
			const uint32* addresses,
			std::list<Channel>& configurationToPopulate);

private:
	static std::map<uint32, Sensor> allSensors;
	static std::map<uint32, Channel> allChannels;

	static bool checkAddress(uint32 requestedSensorAddress);

	static bool checkSensors(uint32 requestedSensorAddress);
	static bool checkChannels(uint32 requestedSensorAddress);
};

#endif
