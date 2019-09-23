#ifndef _INFRASTRUCTURE_COMMON_TYPES_H_
#define _INFRASTRUCTURE_COMMON_TYPES_H_

#include "../../common/CommonTypes.h"

namespace MercuryCommon
{
	struct OutputContainer
	{
		float64 accelValue;
		uint16 checksum;
	};

	union accessHelper
	{
		uint16 data[4];
		uint64 value;
	};
}
#endif
