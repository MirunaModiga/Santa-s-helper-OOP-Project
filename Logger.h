#pragma once
#include <iostream>
#include <fstream>
#include "IException.h"

using namespace std;

class Logger
{
private:
	string filename;
	static Logger* instance;
	Logger() { filename = "jurnal.log"; }
	Logger(const Logger& other) {}
	~Logger() {}
public:
	static Logger* getInstance();
	static void destroyInstance();

	void log_in_actions(string username, string action);

	template<typename T>
	void log_in_raport(T* exception);
};

template<typename T>
void Logger::log_in_raport(T* exception)
{
	time_t result = time(NULL);
	char str[256];
	ctime_s(str, sizeof str, &result);

	fstream file;
	file.open(filename, ios::app);
	file << str << "    ";

	file <<"["<< exception->print() <<"]" << endl;
	file.close();
}
