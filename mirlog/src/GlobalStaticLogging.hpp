#pragma once
#ifndef _GlobalStaticLogging_hpp
#define _GlobalStaticLogging_hpp

#include <ILogger.hpp>

namespace MirrorLog
{
	struct NullLoggerException : public std::exception
	{
		const char* what() const throw()
		{
			return "_Logger is null";
		}
	};

	extern ILogger* _Logger;

	void SetLogger(ILogger& logger);
	void LogInfo(std::string message);
	void LogError(std::string message);
	void LogDebug(std::string message);
	void LogWarning(std::string message);
	bool IsGlobalLoggerSet();
	void UnsetGlobalLogger();
}

#endif // !_GlobalStaticLogging_hpp