// BrightnessAdjust.cpp : Defines the entry point for the console application.
//


#include "ExternalMonitor.h"

#pragma comment(lib, "Dxva2.lib")

static const std::wstring MONITOR_NAME = L"LG ULTRA HD(DisplayPort)";

int main()
{

	ExternalMonitor lg(MONITOR_NAME);
	lg.set_brightness(5);

	return 0;
}

