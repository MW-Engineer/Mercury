#include "Logger.h"

void Logger::log(const char* c_string)
{
	std::cout<<c_string<<std::endl;
}

void Logger::log(std::string str)
{
	std::cout<<str<<std::endl;
}
