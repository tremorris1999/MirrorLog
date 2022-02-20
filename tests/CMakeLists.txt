cmake_minimum_required( VERSION 3.1 )

add_executable(  globalstaticlogging_tests GlobalStaticLoggingTests.cpp)
add_test ( GlobalStaticLogging globalstaticlogging_tests )
target_link_libraries( globalstaticlogging_tests mirrorlog )

add_executable(  consolelogger_tests ConsoleLoggerTests.cpp )
add_test ( ConsoleLogger consolelogger_tests )
target_link_libraries ( consolelogger_tests mirrorlog )