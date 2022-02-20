#include <ConsoleLogger.hpp>

namespace MirrorLog
{
	ConsoleLogger::ConsoleLogger()
	{
		_Buf = &std::cout;
	}

	ConsoleLogger::ConsoleLogger(std::ostream& buf)
	{
		_Buf = &buf;
	}

	void ConsoleLogger::Log(LogType type, std::string message)
	{
		std::string out; 

		switch (type)
		{
		case LogType::Error:
			out = "[ERROR]: " + message;
			break;
		case LogType::Warning:
			out = "[WARNING]: " + message;
			break;
		case LogType::Debug:
			out = "[DEBUG]: " + message;
			break;
		default:
			out = "[INFO]: " + message;
			break;
		}

		*_Buf << out << std::endl;
	}
}