#include <GlobalStaticLogging.hpp>

namespace MirrorLog
{
	ILogger* _Logger;

	void SetLogger(ILogger& logger)
	{
		_Logger = &logger;
	}

	void LogInfo(std::string message)
	{
		if (!_Logger)
			throw NullLoggerException();

		_Logger->Log(LogType::Info, message);
	}

	void LogError(std::string message)
	{
		if (!_Logger)
			throw NullLoggerException();

		_Logger->Log(LogType::Error, message);
	}

	void LogDebug(std::string message)
	{
		if (!_Logger)
			throw NullLoggerException();

		_Logger->Log(LogType::Debug, message);
	}

	void LogWarning(std::string message)
	{
		if (!_Logger)
			throw NullLoggerException();

		_Logger->Log(LogType::Warning, message);
	}

	bool IsGlobalLoggerSet()
	{
		return _Logger;
	}

	void UnsetGlobalLogger()
	{
		_Logger = nullptr;
	}
}