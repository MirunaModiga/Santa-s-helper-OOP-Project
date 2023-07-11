#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <sstream>
#include <Windows.h>
#include <vector>
#include <fstream>

#include "Logger.h"
#include "AppErr.h"
#include "LogErr.h"
#include "WorkshopErr.h"
using namespace std;

class User
{
private:
	string username;
	string password;
	int role; //1-santa,2-elf
	bool connected;
public:
	User() { this->connected = false; }
	string getUsername() { return this->username; }
	virtual void setRole(int role) { this->role = role; }
	string takePasswordFromUser(char sp = '*');
	virtual void createAccount(int role);
	bool authenticate(string log_username, string log_password);
	virtual bool verifySanta();
	virtual bool login();
	virtual~User();
};

