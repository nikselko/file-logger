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

#include "Logger.h"

string Logger::date_to_str(int return_mode)
{
	struct tm tmp_time;

	time_t now = time(nullptr);
	localtime_s(&tmp_time, &now);
	char tmp_buffer[32];

	if (return_mode == 0)
		std::strftime(tmp_buffer, sizeof(tmp_buffer), "[ %F_%H_%M_%S ]: ", &tmp_time);
	else
		std::strftime(tmp_buffer, sizeof(tmp_buffer), "Log_%F_%H_%M_%S.txt", &tmp_time);

	return remove_trash(tmp_buffer);
}

string Logger::remove_trash(char* to_clean)
{
	std::string tmp_string;

	for (int i = 0; to_clean[i] != '\0'; ++i)
		tmp_string += to_clean[i];

	return tmp_string;
}

Logger::Logger() : m_out(FileWriter(date_to_str(1))) {}

Logger& Logger::get()
{
	static Logger the_only_instance{};
	return the_only_instance;
}

void Logger::log(const std::string& msg)
{
	if (m_out.is_open())
		m_out.write(date_to_str(0)).then(msg).newline();
	else
		std::cout << "Logger::log: log file not open\n";
}
