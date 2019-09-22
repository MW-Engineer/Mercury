#ifndef _INTERFACE_H_
#define _INTERFACE_H_
//#include<mutex>
#include "InfrastructureConfiguration.h"
#include "InfrastructureCommonTypes.h"
#include <list>

#include "HWManager.h"

class MercuryTestbed;
/*
 * Singular interface that is visible to the testbed and the application
 */
class Interface
{
public:
	static Interface* getInstance();

private:
	static Interface* instance;

	//std::mutex out;
	//std::mutex in;

	std::list<uint32> activeConfiguration;
	MercuryCommon::OutputContainer oc;


	void initialize();

	Interface();

	/*

	 */
	bool getSensor(uint32 sensorNumber);

	/*
	Called via
	 */
	bool sendOutput(MercuryCommon::OutputContainer& oc);

	friend MercuryTestbed;
};


#endif
