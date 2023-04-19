#pragma once

#ifdef AJW_TIMERDLL
#define AJW_TIMER_DLLEXPORT __declspec(dllexport)
#else
#define AJW_TIMER_DLLEXPORT __declspec(dllimport)
#endif