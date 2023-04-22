#include "EngineTime.h"
#include "Log.h"
#include "Engine.h"

#include <string>

namespace ME
{
	
	/* Sets default values */
	EngineTime::EngineTime() 
		:m_LastTickTime(std::chrono::high_resolution_clock::now()),
	     m_DeltaTime(0),
		 m_Fps(0),
		 m_CurrentDeltaTime(0),
		 m_MiscTime(0),
		 m_ScriptTime(0),
		 m_PhysicsTime(0),
		 m_RenderTime(0)
	{
		m_FpsRecord.reserve(TIME_RECORD_MAX_CAPACITY);
		m_DeltaTimeRecord.reserve(TIME_RECORD_MAX_CAPACITY);
	}	

	/* 
		Gets time since last call in microseconds 
	//
		Calculates frames per seconds 
	*/
	void EngineTime::Update()
	{		
		long delta = GetTimeSinceLastFrame();

		double_t deltaMilliSeconds = delta * 0.001;
		m_DeltaTime = deltaMilliSeconds;
		AddValueToDeltaTimeRecord(m_DeltaTime);

		m_LastTickTime = std::chrono::high_resolution_clock::now();

		if (deltaMilliSeconds != 0) { m_Fps = 1000 / deltaMilliSeconds; }
		else { m_Fps = 10000; }

		AddValueToFpsRecord(m_Fps);

		m_TimeSinceStart += m_DeltaTime / 1000;

		m_CurrentDeltaTime = 0;

		//Log::PrintToLog(ME_Debug, "FPS(" + std::to_string(m_Fps) + ")");
		//Log::PrintToLog(ME_Debug, "Frame(" + std::to_string(m_DeltaTime) + ")");
	}

	void EngineTime::UpdateSubFrame(SubFrameType type)
	{
		long delta = GetTimeSinceLastFrame();

		double_t currentDeltaMilliSeconds = delta * 0.001;	

		if (type == SubFrameType::Misc)
		{
			m_MiscTime = currentDeltaMilliSeconds - m_CurrentDeltaTime;
			if (m_MiscTime < 0) m_MiscTime = 0;
		}
		else if (type == SubFrameType::Script)
		{
			m_ScriptTime = currentDeltaMilliSeconds - m_CurrentDeltaTime;
			if (m_ScriptTime < 0) m_ScriptTime = 0;
		}
		else if (type == SubFrameType::Physics)
		{
			m_PhysicsTime = currentDeltaMilliSeconds - m_CurrentDeltaTime;
			if (m_PhysicsTime < 0) m_PhysicsTime = 0;
		}
		else if (type == SubFrameType::Renderer)
		{
			m_RenderTime = currentDeltaMilliSeconds - m_CurrentDeltaTime;
			if (m_RenderTime < 0) m_RenderTime = 0;
		}
		
		m_CurrentDeltaTime = currentDeltaMilliSeconds;
	}

	int EngineTime::GetFps() const
	{
		return m_Fps;
	}

	int EngineTime::GetAvgFps() const
	{
		return m_AvgFps;
	}

	float EngineTime::GetTimeSinceStart() const
	{
		return m_TimeSinceStart;
	}

	float EngineTime::GetDeltaTime() const
	{
		return m_DeltaTime;
	}

	float EngineTime::GetDeltaTimeInSeconds() const
	{
		return m_DeltaTime * 0.001;
	}

	float EngineTime::GetAvgDeltaTime() const
	{
		return m_AvgDeltaTime;
	}

	float EngineTime::GetMiscTime() const
	{
		return m_MiscTime;
	}

	float EngineTime::GetScriptTime() const
	{
		return m_ScriptTime;
	}

	float EngineTime::GetPhysicsTime() const
	{
		return m_PhysicsTime;
	}

	float EngineTime::GetRenderTime() const
	{
		return m_RenderTime;
	}

	long EngineTime::GetTimeSinceLastFrame()
	{
		return std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count() -
			std::chrono::time_point_cast<std::chrono::microseconds>(m_LastTickTime).time_since_epoch().count();
	}

	void EngineTime::AddValueToFpsRecord(uint32_t value)
	{
		if (m_FpsRecord.size() == TIME_RECORD_MAX_CAPACITY)
		{
			m_AvgFps = CalculateFpsRecordAverage();
			m_FpsRecord.clear();
			m_FpsRecord.push_back(m_AvgFps);
		}
			
		m_FpsRecord.push_back(value);	
	}

	void EngineTime::AddValueToDeltaTimeRecord(float value)
	{
		if (m_DeltaTimeRecord.size() == TIME_RECORD_MAX_CAPACITY)
		{
			m_AvgDeltaTime = CalculateDeltaTimeRecordAverage();
			m_DeltaTimeRecord.clear();
			m_DeltaTimeRecord.push_back(m_AvgDeltaTime);
		}

		m_DeltaTimeRecord.push_back(value);
	}

	uint32_t EngineTime::CalculateFpsRecordAverage()
	{
		uint32_t size = m_FpsRecord.size();
		uint32_t sum = 0;

		for (int i = 0; i < size; i++)		
			sum += m_FpsRecord[i];
		
		sum /= size;

		return sum;
	}

	float EngineTime::CalculateDeltaTimeRecordAverage()
	{
		uint32_t size = m_DeltaTimeRecord.size();
		float sum = 0;

		for (int i = 0; i < size; i++)		
			sum += m_DeltaTimeRecord[i];
		
		sum /= (float)size;

		return sum;
	}
}
