#include "Sensor.h"

Sensor::Sensor() : address(0), readValue(0),dataTrend(Trend())
{
}

Sensor::Sensor(uint32 newAddress) : address(newAddress), readValue(0),dataTrend(Trend())
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

void Sensor::setTrend(Trend newTrend)
{
	dataTrend = newTrend;
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
	//readValue = dataTrend.preformTrend(readValue);
	readValue = dataTrendPtr(readValue);
	return val;
}
