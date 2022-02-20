#include <ConsoleLogger.hpp>
#include <sstream>
#include <string>
#include <vector>

using namespace MirrorLog;

int ConsoleLogger_Default_Success();
int ConsoleLogger_Explicit_Success();
int Log_DefaultBuf();
int Log_CustomBuf();


int main()
{
	std::vector<int> tests;
	int t;

	t = ConsoleLogger_Default_Success();
	std::cout << "Test: Default Constructor --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = ConsoleLogger_Explicit_Success();
	std::cout << "Test: Explicit Constructor --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = Log_DefaultBuf();
	std::cout << "Test: Default Buf --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;
	tests.push_back(t);

	t = Log_CustomBuf();
	std::cout << "Test: Custom Buf --- " << (t == 0 ? "PASS" : "FAIL") << std::endl;

	for (int i = 0; i < tests.size(); i++)
		if (tests[i] != 0)
			return -1;
	std::cout << "\nALL Tests Passed!" << std::endl;
	return 0;
}

int ConsoleLogger_Default_Success()
{
	ILogger* cl = new ConsoleLogger();

	if (!cl)
		return -1;
	delete cl;
	return 0;
}

int ConsoleLogger_Explicit_Success()
{
	std::ostream* buf = new std::ostringstream();
	ConsoleLogger* cl = new ConsoleLogger(*buf);
	delete buf;

	if(!cl)
		return -1;
	delete cl;
	return 0;
}

int Log_DefaultBuf()
{
	std::streambuf* old = std::cout.rdbuf();
	std::ostringstream oss;
	std::cout.rdbuf(oss.rdbuf());
	ConsoleLogger cl;
	cl.Log(LogType::Debug, "testing stdout");
	std::string actual = oss.str();
	std::string expected = "[DEBUG]: testing stdout\n";
	std::cout.rdbuf(old);
	return expected.compare(actual);
}

int Log_CustomBuf()
{
	std::ostringstream oss;
	ConsoleLogger cl(oss);
	cl.Log(LogType::Error, "testing explicit buf");
	std::string expected = "[ERROR]: testing explicit buf\n";
	std::string actual = oss.str();
	return expected.compare(actual);
}
