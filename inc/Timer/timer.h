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
		__int64 ticksPerSecond;//�ʴ� ƽ
		__int64 curTicks;//���� ƽ
		__int64 lastTicks;//���� üũ ������ ƽ
		__int64 lastFPSUpdate;

		unsigned int frameCount;
		float runningTime;//Time ��ü �������� �ð��� �󸶳� �귶�� ����
		float framePerSecond;//�ʴ� ������

		float secondsPerTick;//1ƽ�� �� ��
		float timeElapsed;//1�����Ӵ� �� ��

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
