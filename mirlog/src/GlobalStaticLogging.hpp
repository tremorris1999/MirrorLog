#pragma once
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

	void SetLogger(ILogger& logger);
	void LogInfo(std::string message);
	void LogError(std::string message);
	void LogDebug(std::string message);
	void LogWarning(std::string message);
	void UnsetGlobalLogger();

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

	void UnsetGlobalLogger()
	{
		_Logger = nullptr;
	}
}