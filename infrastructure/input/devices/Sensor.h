#ifndef INFRASTRUCTURE_SENSOR_H_
#define INFRASTRUCTURE_SENSOR_H_

#include "../../../common/CommonTypes.h"
#include "../trend/Trend.h"

/** Forward declared HWManager to allow access to the priave constructor*/
class HWManager;

/**
 * /class Sensor
 * /brief Sensor is encapsulation of a device reading in byte data
 *  as a 32 bit field. The Sensor at this point also generates
 *  the data. How the data is presented is captured in the trend
 *  object.
 */
class Sensor {
public:

	typedef uint32 (*TrendFunc)(uint32);

	~Sensor();

	uint32 getAddress() const;
	void setReadValue(uint32 readValue);
	void setTrend(Trend newTrend);
	void setTrendFunc(TrendFunc newTrend);

	uint32 read();

protected:
	Sensor();
	Sensor(uint32 newAddress);
	//HW Address
	uint32 address;

	//Read Value of address
	uint32 readValue;

	TrendFunc dataTrendPtr;
	Trend dataTrend;
	friend class HWManager;
};

#endif
