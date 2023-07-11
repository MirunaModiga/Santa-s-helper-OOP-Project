#pragma once
#include<iostream>
using namespace std;

enum type_exception { App, Log, Workshop };
class IException
{
protected:

	string mesaj;
	type_exception type;

public:
	IException(string mesaj, type_exception type) :mesaj(mesaj), type(type) {}
	type_exception get_type_excpetie()const { return type; }
	virtual string print() = 0;
};

