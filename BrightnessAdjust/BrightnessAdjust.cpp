// BrightnessAdjust.cpp : Defines the entry point for the console application.
//

#include <thread>

#pragma comment(lib, "Dxva2.lib")

#include "ExternalMonitor.h"
#include "InternalMonitor.h"

static const std::wstring MONITOR_NAME = L"LG ULTRA HD(DisplayPort)";

int main()
{

	ExternalMonitor lg(MONITOR_NAME);
	InternalMonitor surface;

	int brightness;
	int last_brightness = -1;
	while (true)
	{
		brightness = surface.getBrightness();
		if (last_brightness != brightness)
		{
			last_brightness = brightness;
			lg.set_brightness(brightness);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(20));
	}

	return 0;
}
