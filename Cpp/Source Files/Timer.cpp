#include "../Header Files/Timer.h"

//Time Class, for all this
Timer::Timer()
{
    stopped=false, started=false, reseted=false;
}
void Timer::Stop()
{
    miniTimerEnd = std::chrono::high_resolution_clock::now();
    stopped = true;
	started = false;
	reseted = false;
}
void Timer::Start()
{
    miniTimer = std::chrono::high_resolution_clock::now();
    started = true;
}
void Timer::Reset()
{
    miniTimer = std::chrono::high_resolution_clock::now();
    reseted = true;
}

int Timer::getTimeMilliSeconds()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/100);
}

int Timer::getTimeSeconds()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/1000);
}

int Timer::getTimeMinutes()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/10000);
}

int Timer::getTimeHours()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/100000);
}

//DOUBLE
double Timer::getTimeMilliSecondsAvg()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/100);
}

double Timer::getTimeSecondsAvg()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/1000);
}

double Timer::getTimeMinutesAvg()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/10000);
}

double Timer::getTimeHoursAvg()
{
    return ((std::chrono::duration_cast<std::chrono::milliseconds>(miniTimerEnd-miniTimer).count())/100000);
}

bool Timer::resettedCk()
{
   return reseted;
}

bool Timer::startedCk()
{
     return started;
}

bool Timer::stoppedCk()
{
     return stopped;
}

Timer::~Timer()
{
}
