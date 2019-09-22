#ifndef VIRTUAL_PLATFORM_H_
#define VIRTUAL_PLATFORM_H_
#include "../../common/CommonTypes.h"
#include "InfrastructureCommonTypes.h"

class VirtualPlatform
{
public:
	virtual ~VirtualPlatform();

	/*
	 * TODO - recieve external input
	 */
	void processInput();

	/*
	 * TODO
	 */
	void sendOutput();


	MercuryCommon::Sensor* accelerometers;

	/*
	 * Allocate a platform
	 */
	static VirtualPlatform* createPlatform();

private:
	VirtualPlatform();

	void initialize();

	//Private assignment operators to prevent duplication
	VirtualPlatform& operator=(const VirtualPlatform& other);

	//Private copy constructor to prevent duplication
	VirtualPlatform( const VirtualPlatform& other);
};
#endif
