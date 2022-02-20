#pragma once
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