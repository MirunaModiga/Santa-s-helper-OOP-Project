#pragma once
#include <iostream>
#include <vector>

#include "Logger.h"
#include "ElfAccount.h"
#include "SantaAccount.h"

using namespace std;

class IApp
{
private:
	Logger* Admin = Logger::getInstance();
	SantaAccount *Santa;
	vector<ElfAccount*>Elf_list;
public:
	IApp() { BD* database = BD::getInstance(); }
	void menu();
};

