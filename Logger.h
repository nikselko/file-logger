/******************************************************************************
*                                                                             *
*   Program : FileLogger                                                      *
*                                                                             *
*   Date : 15 / 04 / 2021                                                     *
*                                                                             *
*   Programmer : Nikita Seliverstov (nikselko)                                *
*                                                                             *
*                                                                             *
******************************************************************************/

#pragma once

#include <ctime>
#include "FileWriter.h"
#include <fstream>

class Logger
{
public:
	static Logger& get();
	void log(const std::string& msg);
	
private:
	string date_to_str(int return_mode);  //return_mode: 0-datetime, 1-filename
	string remove_trash(char* to_clean);
	static Logger* inst_;	
	
	Logger();
	FileWriter m_out;
};