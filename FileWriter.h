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

#include "includes.h"
#include <cstdio>
#include <string>  

class FileWriter
{
public:
	FileWriter(string file_name);
	~FileWriter();

	bool is_open();

	FileWriter& write(const std::string& m_string);
	FileWriter& write(const char* m_charp);
	FileWriter& write(const char& m_char);
	FileWriter& write(const int& m_int);
	FileWriter& write(const double& m_double);
	FileWriter& write(const bool& m_bool);

	FileWriter& then(const std::string& m_string);
	FileWriter& then(const char* m_charp);
	FileWriter& then(const char& m_char);
	FileWriter& then(const int& m_int);
	FileWriter& then(const double& m_double);
	FileWriter& then(const bool& m_bool);

	FileWriter& newline();
	int lines();
	int size();

private:
	FILE* file_pointer;
	string file_name;

	int characters_amount;
	int new_line_calls;
};

