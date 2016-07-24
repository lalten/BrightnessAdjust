// BrightnessAdjust.cpp : Defines the entry point for the console application.
//

#include <thread>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#pragma comment(lib, "Dxva2.lib")

#include "ExternalMonitor.h"
#include "InternalMonitor.h"

static const std::wstring MONITOR_NAME = L"LG ULTRA HD(DisplayPort)";

int main()
{

	ExternalMonitor lg(MONITOR_NAME);
	InternalMonitor surface;

	int internal_brightness = surface.getBrightness();
	int external_brightness = internal_brightness;

	lg.set_brightness(external_brightness);

	while (true)
	{
		internal_brightness = surface.getBrightness();
		while (external_brightness != internal_brightness)
		{
			external_brightness = external_brightness < internal_brightness ? external_brightness+1 : external_brightness-1;
			lg.set_brightness(external_brightness);
			//std::this_thread::sleep_for(std::chrono::milliseconds(5));
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
	}

	return 0;
}
