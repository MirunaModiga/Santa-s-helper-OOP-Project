#pragma once
#include "BD.h"

class SantaAccount:public User
{
private:
	static SantaAccount* instance;
	SantaAccount() {}
	SantaAccount(const SantaAccount& other) {}
	~SantaAccount(){}
public:
	static SantaAccount* getInstance();
	static void destroyInstance();
	void menu();
};

