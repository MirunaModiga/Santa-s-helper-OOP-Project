#pragma once
#include "IException.h"
class LogErr :public IException
{
public:
	LogErr(string mesaj) :IException(mesaj, Log) {}
	string print() override{ return mesaj; }
};

