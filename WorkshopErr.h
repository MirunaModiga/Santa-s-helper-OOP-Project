#pragma once
#include "IException.h"
class WorkshopErr :public IException
{
public:
	WorkshopErr(std::string mesaj):IException(mesaj,Workshop){}
	string print()override { return mesaj; }
};

