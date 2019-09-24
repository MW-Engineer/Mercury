#ifndef _INTERFACE_H_
#define _INTERFACE_H_

#include "../infrastructure/platform/VirtualPlatform.h"
#include <list>

//Forward declare class to allow for friend
class MercuryTestbed;

/**
 *
 * /brief Singular interface that is visible to the testbed, platform and third party interact.
 * Interface understands the application to Infrastructure to Application and vis versa.
 */

class Interface
{
public:
	static Interface* getInstance();

	bool registerPlatform(VirtualPlatform* newVirtualPlatform);

	/**
	 * /brief Pass through to the Platform to get raw sensor day
	 */
	std::map<uint32, uint32> getSensorOutput();

	/**
	 * /brief Pass through to the Platform to zero the sensors
	 */
	void zeroSensors();
	std::map<uint32, uint32> getChannelOutput();
private:
	static Interface* instance;

	/**
	 * This could be a list of platforms but for now there will only be one
	 */
	VirtualPlatform* virtualPlatform;

	Interface();
	Interface& operator=(const Interface& other);
	Interface(const Interface&);

	friend class MercuryTestbed;
};


#endif
