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
		__int64 ticksPerSecond;//ÃÊ´ç Æ½
		__int64 curTicks;//ÇöÀç Æ½
		__int64 lastTicks;//Áö³­ Ã¼Å© ÁöÁ¡ÀÇ Æ½
		__int64 lastFPSUpdate;

		unsigned int frameCount;
		float runningTime;//Time °´Ã¼ »ý¼ºÀÌÈÄ ½Ã°£ÀÌ ¾ó¸¶³ª Èê·¶³ª ÀúÀå
		float framePerSecond;//ÃÊ´ç ÇÁ·¹ÀÓ

		float secondsPerTick;//1Æ½´ç ¸î ÃÊ
		float timeElapsed;//1ÇÁ·¹ÀÓ´ç ¸î ÃÊ

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
