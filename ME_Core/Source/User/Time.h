#pragma once

namespace ME
{
	struct Time
	{
		Time(const float deltaTime, const float avgDeltaTime, const int AvgFps);

		const float DeltaTime;
		const float AvgDeltaTime;
		const int AvgFps;
	};
}


