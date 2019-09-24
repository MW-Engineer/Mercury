#ifndef _HW_MANAGER_H_
#define _HW_MANAGER_H_

#include <algorithm>
#include <list>
#include <map>

#include "../../common/CommonTypes.h"
#include "../../common/Logger.h"
#include <sstream>

#include "../input/devices/Sensor.h"
#include "../input/trend/Trends.h"

#include "../output/Channel.h"

/**
 * \class HWManager
 * \brief HWManager allocates addresses and verifies that already allocated addresses are not going to be reallocated.
 *
 *	Additionally, responsible for issuing Channel(Output) and Sensor(Input) data objects.
 *
 */
class HWManager
{

public:

	static HWManager* getInstance();
	bool getSensorConfigration(uint32 numberOfSensors,
			const uint32* addresses,
			std::list<Sensor*>& configurationToPopulate);
	bool getChannelConfigration(uint32 numberOfSOutputs,
			const uint32* addresses,
			std::list<Channel*>& configurationToPopulate);

	~HWManager();
private:
	HWManager();
	HWManager& operator=(const HWManager& other);
	HWManager(const HWManager&);

	std::map<uint32, Sensor*> allSensors;
	std::map<uint32, Channel*> allChannels;
	static HWManager* instance;

	bool checkAddress(uint32 requestedSensorAddress);
	bool checkSensors(uint32 requestedSensorAddress);
	bool checkChannels(uint32 requestedSensorAddress);
};

#endif
