#ifndef INFRASTRUCTURE_OUTPUT_CHANNEL_H_
#define INFRASTRUCTURE_OUTPUT_CHANNEL_H_

#include "../../common/CommonTypes.h"

/** Forward declared HWManager to allow access to the priave constructor*/
class HWManager;

/**
 * A Channel represents a single channel of output from a application
 */
class Channel {
public:
	virtual ~Channel();
	bool isReadingValid();

//	Channel& operator=(const Channel& other);
private:
	Channel();
	Channel(uint32 newAddress);

	//HW Address
	uint32 address;

	//Simulated Memory value
	uint64 outputValue;

	//checksum
	uint16 checksum;

	friend class HWManager;
};

#endif /* REPO_MERCURY_INFRASTRUCTURE_OUTPUT_CHANNEL_H_ */
