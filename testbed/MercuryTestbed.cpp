//Infrastructue

#include "MercuryTestbed.h"

/**
 * /brief MercuryTestbed will be the
 */
void MercuryTestbed::StartTetbed()
{
	if(!MercuryTestbed::isStarted)
	{
		bool status = false;

		status = intializeComponents();
		if(status)
		{
			Logger::log("Successfully initialized.");
		}else
		{
			Logger::log("Error Starting up.");
			return;
		}

		std::cout<<"All Hardware Initialized Successfully."<<std::endl;


		std::string input;
		bool run = true;
		while(run)
		{
			displayMenu();
			std::cin>>input;

			switch(validateInput(input))
			{
				case MenuConfiguration::OPTION_1:
					std::cout<<"All Sensor values: " << std::endl;
					displayAllData(Interface::getInstance()->getSensorOutput());
					break;
				case MenuConfiguration::OPTION_2:
					Interface::getInstance()->zeroSensors();
					std::cout<<"Sensors have been Zeroed."<<std::endl;
					break;
				case MenuConfiguration::OPTION_3:
					std::cout<<"All Channel values: " << std::endl;
					displayAllData(Interface::getInstance()->getChannelOutput());
					break;
				case MenuConfiguration::OPTION_4:
					run = false;
					break;
				default:
					std::cout<<"Sorry, that is not an valid."<<std::endl;
			};
		}

		std::cout<<"Come again and have a good day!"<<std::endl;
	}
}

uint8 MercuryTestbed::validateInput(const std::string input)
{
	uint8 option = 0;
	for(int x = 0;x<MenuConfiguration::NUMBER_OF_OPTIONS;x++){
		if(std::stoi(input) == MenuConfiguration::All_OPTIONS[x])
	    {
			option = MenuConfiguration::All_OPTIONS[x];
	    }
	}
	return option;

}

void MercuryTestbed::displayMenu()
{
	std::cout<<"Please choose of one of the following options. " <<std::endl
			<< "Indicate your choice by entering the correspond number: "<<std::endl;
	std::cout << MenuConfiguration::OPTION_1 <<") Read Sensors" << std::endl;
	std::cout << MenuConfiguration::OPTION_2 <<") Zero Sensors" << std::endl;
	std::cout << MenuConfiguration::OPTION_3 <<") Read Channel" << std::endl;
	std::cout << MenuConfiguration::OPTION_4 <<") Quit" << std::endl;
}

void MercuryTestbed::displayAllData(std::map<uint32,uint32> valMap)
{
	std::map<uint32, uint32>::iterator it = valMap.begin();
	while (it != valMap.end())
	{
		std::cout<<"Address: "<<std::hex<<it->first << " Value: "<< it->second<<std::endl;
		it++;
	}
}



bool MercuryTestbed::intializeComponents()
{
	bool status = false;

	//Create Platform
	VirtualPlatform* thePlatformPtr = VirtualPlatform::getPlatform();
	Interface* theInterfacePtr = Interface::getInstance();

	//Static instance successfully allocated
	if(theInterfacePtr != 0 && thePlatformPtr != 0)
	{
		status = thePlatformPtr->initialize();

		theInterfacePtr->registerPlatform(thePlatformPtr);
		if(!status)
		{
			Logger::log("Error Initializing platform and interface");
		}
	}
	else
	{
		Logger::log("Error allocating static instances");

	}

	return status;
}

bool MercuryTestbed::isStarted = false;
