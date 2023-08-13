#pragma once

#include <iostream>
#include <string>

enum class LogLevel
{
	INFO,
	WARN,
	ERROR
};

class LogUtil
{
public:
	static void log(LogLevel level, const std::string &message)
	{
		switch (level)
		{
		case LogLevel::INFO:
			std::cout << "[INFO] ";
			break;
		case LogLevel::WARN:
			std::cout << "[WARN] ";
			break;
		case LogLevel::ERROR:
			std::cout << "[ERROR] ";
			break;
		}
		std::cout << message << std::endl;
	}
};
