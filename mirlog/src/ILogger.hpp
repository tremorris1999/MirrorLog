#pragma once
#ifndef _ILogger_hpp
#define _ILogger_hpp

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

#endif // !_ILogger_hpp