#ifndef INFRASTRUCTURE_TREND_H_
#define INFRASTRUCTURE_TREND_H_
#include "../../../common/CommonTypes.h"

class Trend {
public:
	Trend();
	virtual ~Trend();
	virtual uint32 preformTrend(uint32 value);
};

#endif
