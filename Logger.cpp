#include "Logger.h"
Logger* Logger::instance = nullptr;

Logger* Logger::getInstance()
{
	if (instance == nullptr) {
		instance = new Logger();
	}

	return instance;
}
void Logger::destroyInstance()
{
	if (Logger::instance != nullptr)
	{
		delete instance;
		instance = nullptr;
	}
}

void Logger::log_in_actions(string username, string action)
{
	time_t result = time(NULL);
	char str[256];
	ctime_s(str, sizeof str, &result);

	fstream file;
	file.open(filename,ios::app);
	file << str << "    ";

	file << "[" << username << "]      " << "[" << action << "]" << endl;
	file.close();
}

