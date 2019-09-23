#ifndef INFRASTRUCTURE_LINEARTREND_H_
#define INFRASTRUCTURE_LINEARTREND_H_
#include "Trend.h"

class LinearTrend : public Trend
{
public:
	static uint32 linearTrend(uint32);
	LinearTrend();
	~LinearTrend();

	uint32 preformTrend(uint32 value);

	void setStep(uint32 newStep);
	uint32 getStep();
private:
	uint32 step;
};

#endif
