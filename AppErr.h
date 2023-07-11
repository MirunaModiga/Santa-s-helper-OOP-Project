#pragma once
#include "IException.h"
class AppErr :public IException
{
public:
	AppErr(string mesaj) :IException(mesaj, App) {}
	string print()override { return mesaj; }
};

