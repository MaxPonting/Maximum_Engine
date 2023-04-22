#pragma once

/* C++ */
#include <chrono>
#include <string>
#include <vector>

#define TIME_RECORD_MAX_CAPACITY 60

namespace ME
{
	class EngineTime final
	{
	public:

		/* CONSTRUCTOR */
		EngineTime();

		/* ENUM CLASS */
		enum class SubFrameType { Misc, Script, Physics, Renderer };

		/* PUBLIC METHODS */
		void Update();
		void UpdateSubFrame(SubFrameType type);

		/* GETTERS */
		int GetFps() const;
		int GetAvgFps() const;
		float GetTimeSinceStart() const;
		float GetDeltaTime() const;
		float GetDeltaTimeInSeconds() const;
		float GetAvgDeltaTime() const;
		float GetMiscTime() const;
		float GetScriptTime() const;
		float GetPhysicsTime() const;
		float GetRenderTime() const;
		

	private:

		/* PRIVATE METHODS */
		long GetTimeSinceLastFrame();
		void AddValueToFpsRecord(uint32_t value);
		void AddValueToDeltaTimeRecord(float value);

		uint32_t CalculateFpsRecordAverage();
		float CalculateDeltaTimeRecordAverage();
		
		/* PRIVATE MEMBERS */
		std::chrono::time_point<std::chrono::high_resolution_clock> m_LastTickTime;	
		int m_Fps;
		int m_AvgFps;
		float m_TimeSinceStart;
		float m_DeltaTime;
		float m_CurrentDeltaTime;
		float m_AvgDeltaTime;
		float m_MiscTime;
		float m_ScriptTime;
		float m_PhysicsTime;
		float m_RenderTime;

		std::vector<uint32_t> m_FpsRecord;
		std::vector<float> m_DeltaTimeRecord;
	};
}

