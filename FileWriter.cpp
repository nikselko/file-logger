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

#include "FileWriter.h"

FileWriter::FileWriter(string m_file_name) :
	file_name{ m_file_name },
	characters_amount{ 0 },
	new_line_calls{ 0 }
{
	fopen_s(&file_pointer, file_name.c_str(), "a+");
}

FileWriter::~FileWriter()
{
	std::fflush(file_pointer);

	if (is_open())
		fclose(file_pointer);
}

bool FileWriter::is_open()
{
	if (file_pointer == NULL)
		return false;
	else
		return true;
}

FileWriter& FileWriter::write(const std::string& m_string)
{
	if (is_open())
	{
		const char* tmp_buffer = m_string.c_str();
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::write(const char* m_charp)
{
	if (is_open())
	{
		characters_amount =  characters_amount + std::fprintf(file_pointer, m_charp);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::write(const char& m_char)
{
	if (is_open())
	{
		characters_amount =  characters_amount + std::fprintf(file_pointer, &m_char);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::write(const int& m_int)
{
	if (is_open())
	{
		const char* tmp_buffer = (std::to_string(m_int)).c_str();
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::write(const double& m_double)
{
	if (is_open())
	{
		const char* tmp_buffer = (std::to_string(m_double)).c_str();
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::write(const bool& m_bool)
{
	if (is_open())
	{
		const char* tmp_buffer;

		if (m_bool)
			tmp_buffer = "true";
		else
			tmp_buffer = "false";
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::then(const std::string& m_string)
{
	if (is_open())
	{
		const char* tmp_buffer = m_string.c_str();
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::then(const char* m_charp)
{
	if (is_open())
	{
		characters_amount =  characters_amount + std::fprintf(file_pointer, m_charp);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::then(const char& m_char)
{
	if (is_open())
	{
		characters_amount =  characters_amount + std::fprintf(file_pointer, &m_char);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::then(const int& m_int)
{
	if (is_open())
	{
		const char* tmp_buffer = (std::to_string(m_int)).c_str();
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::then(const double& m_double)
{
	if (is_open())
	{
		const char* tmp_buffer = (std::to_string(m_double)).c_str();
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::then(const bool& m_bool)
{
	if (is_open())
	{
		const char* tmp_buffer;

		if (m_bool)
			tmp_buffer = "true";
		else
			tmp_buffer = "false";
		characters_amount =  characters_amount + std::fprintf(file_pointer, tmp_buffer);

		std::fflush(file_pointer);
	}

	return *this;
}

FileWriter& FileWriter::newline()
{
	if (is_open())
	{
		characters_amount =  characters_amount + std::fprintf(file_pointer, "\n");
		new_line_calls++;

		std::fflush(file_pointer);
	}

	return *this;
}

int FileWriter::lines()
{
	fclose(file_pointer);
	fopen_s(&file_pointer, file_name.c_str(), "r");

	int tmp_counter = 1;
	char tmp_compare = ' ';

	if (is_open())
	{
		while (fscanf_s(file_pointer, "%c", &tmp_compare, 1))
		{
			if (tmp_compare == '\n')
				tmp_counter++;
			if (fscanf_s(file_pointer, "%c", &tmp_compare, 1) < 0)
				break;
		}
	}

	fclose(file_pointer);
	fopen_s(&file_pointer, file_name.c_str(), "a+");

	tmp_counter = tmp_counter - new_line_calls;
	new_line_calls--;

	return tmp_counter;
}

int FileWriter::size()
{
	return characters_amount+1;
}