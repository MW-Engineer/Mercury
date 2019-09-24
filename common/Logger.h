#ifndef LOGGER_H_
#define LOGGER_H_

#include <stdio.h>
#include <string>
#include <iostream>

/*
 * Basic Logger class that can be replaced later with more robust capabilities
 */
class Logger
{
public:
	static void log(const char* c_string);
	static void log(std::string str);
};
#endif
