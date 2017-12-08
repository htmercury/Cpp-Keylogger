#ifndef HELPER_H
#define HELPER_H

#include <ctime>
#include <string>
#include <sstream>

namespace Helper // custom namespace to store our custom data types
{
	template <class T>

	std::string ToString(const T &);

	struct DateTime
	{
		DateTime()
		{
			time_t ms;
			time(&ms);

			struct tm* info = localtime(&ms);

			D = info->tm_mday;
			m = info->tm_mon + 1; // need to add 1 since january is represented 0
			y = 1900 + info->tm_year; // reference year since C came in the 70s and locatime returns time from that particular day until present day
			M = info->tm_min;
			H = info->tm_hour;
			S = info->tm_sec;
		}
	};
}

#endif // HELPER_H