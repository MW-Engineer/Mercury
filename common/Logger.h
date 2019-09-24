#ifndef LOGGER_H_
#define LOGGER_H_

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
