#pragma once
#include<Windows.h>
class Timer {
	Timer() {

		QueryPerformanceFrequency((LARGE_INTEGER*)&tick);

	}

	void Strat() {
		QueryPerformanceCounter((LARGE_INTEGER*)&start);
	}
	void End() {
		QueryPerformanceCounter((LARGE_INTEGER*)&end);
	}
	float Running() {
		return (float)((double)(end - start) / tick * 1000.0f);
	}
private:


	__int64 tick;
	__int64 start, end;




};