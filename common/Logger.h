#ifndef VIRTUAL_PLATFORM_H_
#define VIRTUAL_PLATFORM_H_

#include <stdio.h>
#include <string>
#include <iostream>
class Logger
{
public:
	static void log(const char* c_string);
	static void log(std::string str);
};
#endif
