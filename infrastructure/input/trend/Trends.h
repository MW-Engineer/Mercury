#ifndef INFRASTRUCTURE_TRENDS_H_
#define INFRASTRUCTURE_TRENDS_H_
#include "../../../common/CommonTypes.h"

/*
 * Grouping of static Trend functions
 */
namespace Trends
{
	static uint32 preformStableTrend(uint32 value)
	{
		return value;
	}

	static uint32 preformLinearTrend(uint32 value)
	{
		return value + 1;
	}
}
#endif
