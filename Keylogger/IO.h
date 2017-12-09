#ifndef IO_H
#define IO_H

#include <string>
#include <cstdlib>
#include <fstream>
#include <Windows.h>
#include "Helper.h"
#include "Base64.h"

namespace IO
{
	std::string GetOurPath(const bool append_separator = false) //checks if the backslash is needed at the end of our path, add if needed
	{
		std::string appdata_dir(getenv("APPDATA")); // finds AppData directory path
		std::string full = appdata_dir + "\\Microsoft\\CLR";
		return full + (append_separator ? "\\" : "");
	}

	bool MkOneDr(std::string path) // checks if directory already exists or not
	{
		return (bool)CreateDirectory(path.c_str(), NULL) || GetLastError() == ERROR_ALREADY_EXISTS;
	}

}


#endif // IO_H