#pragma once
#include <chrono>
// TIMER CLASS
// AMANUEL BOGALE
class Timer
{
public:
	Timer();
	~Timer();
	void Start();
    void Stop();
    void Reset();
    bool resettedCk();
    bool startedCk();
    bool stoppedCk();
    int getTimeHours();
    int getTimeMinutes();
    int getTimeSeconds();
    int getTimeMilliSeconds();
    double getTimeHoursAvg();
    double getTimeMinutesAvg();
    double getTimeSecondsAvg();
    double getTimeMilliSecondsAvg();
private:
    std::chrono::high_resolution_clock::time_point miniTimer,miniTimerEnd;
    bool started,stopped,reseted;
};