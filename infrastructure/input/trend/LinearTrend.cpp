/*
 * LinearTrend.cpp
 *
 *  Created on: Sep 22, 2019
 *      Author: MW
 */

#include "LinearTrend.h"

LinearTrend::LinearTrend() : step(0)
{

}

LinearTrend::~LinearTrend() {
	// TODO Auto-generated destructor stub
}

uint32 LinearTrend::preformTrend(uint32 value)
{
	return value + step;
}

void LinearTrend::setStep(uint32 newStep)
{
	step = newStep;
}
uint32 LinearTrend::getStep()
{
	return step;
}

uint32 LinearTrend::linearTrend(uint32 value)
{
	return value + 1;
}
