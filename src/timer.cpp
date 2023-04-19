#include "pch.h"

#include "Timer\timer.h"

namespace ajwCommon
{
	Time::Time()
		: curTicks(0), lastFPSUpdate(0),
		frameCount(0), runningTime(0), framePerSecond(0)
	{
		QueryPerformanceFrequency((LARGE_INTEGER*)&ticksPerSecond);//�ʴ� ƽ�� ����
		QueryPerformanceCounter((LARGE_INTEGER*)&lastTicks);//���۽��� ƽ�� ����
		secondsPerTick = 1.0f / ticksPerSecond;//1ƽ�� �� ��
	}

	Time::~Time()
	{
	}

	void Time::Update()
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&curTicks);//���� ƽ�� �޾ƿ´�
		timeElapsed = (float)(curTicks - lastTicks) * secondsPerTick;//���� ������Ʈ���� �� �ʰ� �귶����, ex) 1ƽ�� 0.2�ʶ�� 5ƽ�̶�� 1��
		runningTime += timeElapsed;//Time ��ü �������� �ð��� �󸶳� �귶�� ����

		frameCount++;
		if (curTicks - lastFPSUpdate >= ticksPerSecond)//���� ������Ʈ�� ������ ƽ�� �ʴ� ƽ�� �Ѿ�� == 1�� ���� 
		{
			float tempCurTime = (float)curTicks * secondsPerTick;//ƽ ī��Ʈ ���۽� ���� ���ݱ��� ���� ��������
			float tempLastTime = (float)lastFPSUpdate * secondsPerTick;//ƽ ī��Ʈ ���۽ú��� ���� FPS������Ʈ���� ���� ��������
			framePerSecond = (float)frameCount / (tempCurTime - tempLastTime);//�ʴ� ������ ��

			lastFPSUpdate = curTicks;//�̹� ������Ʈ�� �� ƽ °�� ����ƴ��� ����
			frameCount = 0;//������ ī��Ʈ �ʱ�ȭ
		}

		lastTicks = curTicks;//���� ������Ʈ�� ����� ƽ ���� ����


		//
		/*char FPS[3];
		memcpy(FPS, &framePerSecond, sizeof(float));
		char* FPSShow = FPS;
		Graphic->Print(560, 0, FPSShow);*/

	}

	void Time::StartCheckTime(std::string keyword)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&stopTimerTick);

		stopTimer[keyword] = stopTimerTick;
	}

	float Time::EndCheckTime(std::string keyword)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&stopTimerTick);

		return (float)(stopTimerTick - stopTimer[keyword]) * secondsPerTick;
	}

}