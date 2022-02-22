cmake_minimum_required ( VERSION 3.1 )

add_library ( mirrorlog
	src/LogType.hpp
	src/ILogger.hpp
	src/GlobalStaticLogging.hpp
	src/GlobalStaticLogging.cpp
	src/ConsoleLogger.hpp
	src/ConsoleLogger.cpp)

target_include_directories( mirrorlog PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src )