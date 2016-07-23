#include "InternalMonitor.h"

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

const std::string InternalMonitor::exec(const char* cmd) {
	char buffer[128];
	std::string result = "";
	std::shared_ptr<FILE> pipe(_popen(cmd, "r"), _pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer, 128, pipe.get()) != NULL)
			result += buffer;
	}
	return result;
}

InternalMonitor::InternalMonitor()
{
}


InternalMonitor::~InternalMonitor()
{
}

const unsigned int InternalMonitor::getBrightness()
{
	return std::stoi( exec("powershell \"(Get-WmiObject -ns root/wmi -class wmiMonitorBrightness).CurrentBrightness\"") );
}
