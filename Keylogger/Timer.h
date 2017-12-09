#ifndef TIMER_H
#define TIMER_H

#include <thread>
#include <chrono>

class Timer
{
	std::thread Thread; // used for asynchronous code execution without blocking main thread
	bool Alive = false; // check if timer is running
	long CallNumber = -1L; // how many times we would like to call a certain function
	long repeat_count = -1L; // count amount of times a certain function has been called
	std::chrono::milliseconds interval = std::chrono::milliseconds(0); //interval between function calls, default is 0
	std::function<void(void)> funct = nullptr; // function that takes nothing and returns nothing

	void SleepAndRun()
	{
		std::this_thread::sleep_for(interval); //pause thread for certain time interval
		if (Alive)
			Function()(); // double parenthesis - first calls Function and second calls function that Function returns
	}

	void ThreadFunc()
	{
		if (CallNumber == Infinite)
			while (Alive)
				SleepAndRun();
		else
			while (repeat_count--)
				SleepAndRun();
	}
};

#endif // TIMER_H