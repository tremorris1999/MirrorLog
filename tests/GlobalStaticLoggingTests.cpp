#include <GlobalStaticLogging.hpp>
#include <ConsoleLogger.hpp>
#include <vector>
#include <sstream>

using namespace MirrorLog;

int LogX_NullLogger_ThrowsException();
int LogInfo_Success();
int LogWarning_Success();
int LogError_Success();
int LogDebug_Success();
int UnsetGlobalLogger_Success();

int main()
{
	std::vector<int> tests;
	int t;

	t = LogX_NullLogger_ThrowsException();
	std::cout << "Test: LogX_NullLogger --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = LogInfo_Success();
	std::cout << "Test: LogInfo --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = LogWarning_Success();
	std::cout << "Test: LogWarning --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = LogError_Success();
	std::cout << "Test: LogError --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = LogDebug_Success();
	std::cout << "Test: LogDebug --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = UnsetGlobalLogger_Success();
	std::cout << "Test: UnsetGlobalLogger --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	for (int i = 0; i < tests.size(); i++)
		if (tests[i] != 0)
			return -1;
	std::cout << "\nALL Tests Passed!" << std::endl;
	return 0;
}

int LogX_NullLogger_ThrowsException()
{
	try
	{
		LogInfo("this should throw");
	}
	catch (std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}

	return -1;
}

int LogInfo_Success()
{
	std::ostringstream oss;
	ConsoleLogger cl(oss);
	SetLogger(cl);
	LogInfo("test");
	std::string expected = "[INFO]: test\n";
	std::string actual = oss.str();
	return expected.compare(actual);
}

int LogWarning_Success()
{
	std::ostringstream oss;
	ConsoleLogger cl(oss);
	SetLogger(cl);
	LogWarning("test");
	std::string expected = "[WARNING]: test\n";
	std::string actual = oss.str();
	return expected.compare(actual);
}

int LogError_Success()
{
	std::ostringstream oss;
	ConsoleLogger cl(oss);
	SetLogger(cl);
	LogError("test");
	std::string expected = "[ERROR]: test\n";
	std::string actual = oss.str();
	return expected.compare(actual);
}

int LogDebug_Success()
{
	std::ostringstream oss;
	ConsoleLogger cl(oss);
	SetLogger(cl);
	LogDebug("test");
	std::string expected = "[DEBUG]: test\n";
	std::string actual = oss.str();
	return expected.compare(actual);
}

int UnsetGlobalLogger_Success()
{
	ConsoleLogger cl;
	SetLogger(cl);
	UnsetGlobalLogger();

	if (!_Logger)
		return 0;
	return -1;
}
