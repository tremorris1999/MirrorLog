#pragma once
#ifndef _ConsoleLogger_hpp
#define _ConsoleLogger_hpp

#include <ILogger.hpp>

namespace MirrorLog
{
	class ConsoleLogger : public ILogger
	{
	public:
		ConsoleLogger();
		ConsoleLogger(std::ostream& buf);
		~ConsoleLogger() override {}

		void Log(LogType type, std::string message) override;

	private:
		std::ostream* _Buf;
	};
}

#endif // !_ConsoleLogger_hpp