#include "Time.h"

namespace ME
{
	Time::Time(const float deltaTime, const float avgDeltaTime, const int avgFps) :
		DeltaTime(deltaTime), AvgDeltaTime(avgDeltaTime), AvgFps(avgFps)
	{}
}
