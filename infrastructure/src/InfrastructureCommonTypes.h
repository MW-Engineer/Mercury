#ifndef _INFRASTRUCTURE_COMMON_TYPES_H_
#define _INFRASTRUCTURE_COMMON_TYPES_H_

#include "../../common/CommonTypes.h"

namespace MercuryCommon
{

	struct Sensor
	{
		//HW Address
		uint32 address;

		//Simulated Memory value
		uint32 readValue;
	};

	struct OutputContainer
	{
		float64 accelValue;
		uint16 checksum;
	};
}
#endif
