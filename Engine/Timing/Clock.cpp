#include "Clock.h"

namespace Timing
{
	bool Clock::initialize()
	{
		bool success = QueryPerformanceFrequency(&timeFrequency);
		if (!success)
		{
			return false;
		}
		return QueryPerformanceCounter(&deltaLastFrame);
	}

	bool Clock::shutdown() { return true; }

	void Clock::newFrame()
	{
		LARGE_INTEGER tempDelta;
		QueryPerformanceCounter(&tempDelta);
		timeLastFrame = (float)(tempDelta.QuadPart - deltaLastFrame.QuadPart) / timeFrequency.QuadPart;
		deltaLastFrame.QuadPart = tempDelta.QuadPart;
		return;
	}

	float Clock::timeElapsedLastFrame() const
	{
		return timeLastFrame;
	}
}