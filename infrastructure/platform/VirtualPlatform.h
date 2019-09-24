#ifndef VIRTUAL_PLATFORM_H_
#define VIRTUAL_PLATFORM_H_

#include "../../common/CommonTypes.h"
#include "../../common/Logger.h"
#include "../common/InfrastructureCommonTypes.h"
#include "../common/InfrastructureConfiguration.h"
#include <list>

#include "../manager/HWManager.h"
/**
 * @class VirtualPlatform
 * @brief Virtual Platform represents a the underlying platform that
 * all sensors are connected and all output is received from the application.
 */

class VirtualPlatform
{
public:
	virtual ~VirtualPlatform();

	std::map<uint32, uint32> getSensorOutput();
	void zeroSensors();

	/**
	 * @brief createPlatform gets a platform from the current configuration.
	 * In an ideal world there would be the ability to have multiple platforms.
	 * As this is not an ideal world, one will have to do for now.
	 */
	static VirtualPlatform* getPlatform();

private:
	static VirtualPlatform* instance;

	std::list<Sensor> activeSensors;
	std::list<Channel> activeChannels;

	VirtualPlatform();

	bool initialize();

	//Private assignment operators to prevent duplication
	VirtualPlatform& operator=(const VirtualPlatform& other);

	//Private copy constructor to prevent duplication
	VirtualPlatform( const VirtualPlatform& other);

	friend class MercuryTestbed;
};
#endif
