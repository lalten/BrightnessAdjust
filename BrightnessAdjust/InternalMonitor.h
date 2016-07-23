#pragma once

#include <string>

class InternalMonitor
{
public:
	InternalMonitor();
	~InternalMonitor();

	const unsigned int getBrightness();
private:
	static const std::string exec(const char* cmd);
};

