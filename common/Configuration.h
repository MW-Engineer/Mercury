#ifndef _MERCURY_CONFIG_H_
#define _MERCURY_CONFIG_H_

#include "CommonTypes.h"

namespace MercuryConfig
{
	//Sensor Groups
	enum HardwareGroup {
		ACCELEROMETERS,
		NUMBER_OF_GROUPS
	};

	static const uint32 NUMER_OF_ACCELEROMETERS = 3;

	struct SensorGroup
	{
		HardwareGroup name;
	};

	//Used to write out
	struct OutputContainer
	{
		float64 accelValue;
		uint16 checksum;
	};
}


#endif
