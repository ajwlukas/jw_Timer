#pragma once

#include <Windows.h>
#include <string>
#include <unordered_map>

#include "dll.h"

namespace ajwCommon
{
#pragma once

	class AJW_TIMER_DLLEXPORT Time
	{
	private:
		__int64 ticksPerSecond;//초당 틱
		__int64 curTicks;//현재 틱
		__int64 lastTicks;//지난 체크 지점의 틱
		__int64 lastFPSUpdate;

		unsigned int frameCount;
		float runningTime;//Time 객체 생성이후 시간이 얼마나 흘렀나 저장
		float framePerSecond;//초당 프레임

		float secondsPerTick;//1틱당 몇 초
		float timeElapsed;//1프레임당 몇 초

		Time();
		~Time();

	public:
		static Time& Get() { static Time instance; return instance; }

		Time(Time const&) = delete;
		void operator=(Time const&) = delete;

		void Update();


		float Delta() { return timeElapsed; }
		float FPS() { return framePerSecond; }
		float Running() { return runningTime; }

		void StartCheckTime(std::string keyword);
		float EndCheckTime(std::string keyword);
	private:
		std::unordered_map<std::string, __int64> stopTimer;
		__int64 stopTimerTick;
	};
}
