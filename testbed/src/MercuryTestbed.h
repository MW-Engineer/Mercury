#ifndef MERCURY_TESTBED_H_
#define MERCURY_TESTBED_H_



//Infrastructue
#include "../../infrastructure/src/Interface.h"


class MercuryTestbed
{
public:
	static void StartTetbed();
private:
	static bool isStarted;
};

#endif
