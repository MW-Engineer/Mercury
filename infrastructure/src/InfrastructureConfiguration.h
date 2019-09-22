#ifndef _INFRASTRUCTURE_CONFIGURATION_H_
#define _INFRASTRUCTURE_CONFIGURATION_H_

#include "../../common/CommonTypes.h"

namespace MercuryInputConfig
{
	//start infrastructure
	static const uint32 NUMBER_OF_ACCELEROMETERS = 3;

	//Sensor Address
	static const uint32 ACCEL_1_ADDRESS = 0x00000001;
	static const uint32 ACCEL_2_ADDRESS = 0x00000002;
	static const uint32 ACCEL_3_ADDRESS = 0x00000003;

	//Sensor Address
	static const uint32 ALL_ACCELEROMETERS[NUMBER_OF_ACCELEROMETERS] =
	{
		ACCEL_1_ADDRESS,
		ACCEL_2_ADDRESS,
		ACCEL_3_ADDRESS
	};

}

#endif
