#pragma once
#include<iostream>
#include <LogType.hpp>

namespace MirrorLog
{
	class ILogger
	{
	public:
		virtual void Log(LogType type, std::string message) = 0;
		virtual ~ILogger() {};
	};
}