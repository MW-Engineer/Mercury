#include "Sensor.h"

Sensor::Sensor() : address(0), readValue(0),dataTrendPtr(Trends::preformStableTrend)
{
}

Sensor::Sensor(uint32 newAddress) : address(newAddress), readValue(0),dataTrendPtr(Trends::preformStableTrend)
{
}

Sensor::~Sensor()
{
}

void Sensor::setTrendFunc(TrendFunc newTrend)
{
	if(newTrend!=0)
	{
		dataTrendPtr = newTrend;
	}
}

uint32 Sensor::getAddress() const {
	return address;
}


void Sensor::setReadValue(uint32 readValue) {
	this->readValue = readValue;
}

uint32 Sensor::read()
{
	uint32 val = readValue;
	readValue = dataTrendPtr(readValue);
	return val;
}
