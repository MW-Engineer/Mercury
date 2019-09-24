#ifndef INFRASTRUCTURE_SENSOR_H_
#define INFRASTRUCTURE_SENSOR_H_

#include "../../../common/CommonTypes.h"
#include "../trend/Trends.h"

/** Forward declared HWManager to allow access to the private constructor*/
class HWManager;

/**
 * /class Sensor
 * /brief Sensor is encapsulation of a device reading in byte data
 *  as a 32 bit field. The Sensor at this point also generates
 *  the data. How, the data is manipulated is captured by the TrendFunc
 */
class Sensor {
public:

	typedef uint32 (*TrendFunc)(uint32);

	~Sensor();

	uint32 getAddress() const;
	void setReadValue(uint32 readValue);
	void setTrendFunc(TrendFunc newTrend);

	uint32 read();

protected:
	Sensor();
	Sensor(uint32 newAddress);
	Sensor& operator=(const Sensor& other);
	Sensor(const Sensor&);
	//HW Address
	uint32 address;

	//Read Value of address
	uint32 readValue;

	//Function pointer
	TrendFunc dataTrendPtr;

	friend class HWManager;
};

#endif
