#include "User.h"

string User::takePasswordFromUser(char sp)
{
	string passwd = "";
	char ch_ipt;
	while (true) {
		ch_ipt = _getch();
		if (ch_ipt == 13) {
			cout << endl;
			return passwd;
		}
		else if (ch_ipt == 8 && passwd.length() != 0) {
			passwd.pop_back();
			cout << "\b \b";
			continue;
		}
		else if (ch_ipt == 8 && passwd.length() == 0) {
			continue;
		}
		passwd.push_back(ch_ipt);
		cout << sp;
	}
}

void User::createAccount(int role)
{
	ifstream file;
	file.open("BDAccounts.txt");
	bool ok = true;
	while (ok) {
		cout << "Introduce username:" << endl;
		cin >> username;
		bool ok1 = false;
		while (!file.eof()) {
			string line;
			istringstream iss;
			string token;
			getline(file, line);
			iss.clear();
			iss.str(line);
			iss >> token;
			if (username == token) {
				cout<<"This username already exists..Try again"<<endl;
				ok1 = true;
				string pass, role;
				iss >> pass >> role;
				if (stoi(role) == 1)
					return;
			}
		}
		if (ok1 == false) {
			ok = false;
		}
		else {
			file.close();
			file.open("BDAccounts.txt");
		}
	}
	file.close();
	cout << "Introduce password:" << endl;
	password = takePasswordFromUser();

	Logger::getInstance()->log_in_actions(username, "created account");

	fstream file1;
	file1.open("BDAccounts.txt", ios::app);
	file1 << username << " " << password <<" "<<role << endl;
	file1.close();
}

bool User::authenticate(string log_username, string log_password)
{
	fstream file;
	file.open("BDAccounts.txt");
	string line;
	string token;
	istringstream iss;
	string IntroducedPassword;
	bool ok = false;
	while (getline(file, line)) {
		iss.clear();
		iss.str(line);
		iss >> token;
		if (log_username == token) {
			ok = true;
		}
	}
	file.close();
	file.open("BDAccounts.txt");
	if (!ok) {
		cout << "Wrong username! Try again..." << endl;
		Sleep(2000);
		return false;
	}
	else {
		while (getline(file, line)) {
			iss.clear();
			iss.str(line);
			iss >> token;
			if (log_username == token) {
				iss >> token;
				if (log_password != token) {
					for (int i = 0; i < 2 && !this->connected; i++) {
						cout << "Wrong password! Try again...";
						cout << "\nYou have " << 2 - i << " attemps left!\n";
						cout << "Please enter your password: ";
						char ch = 0;
						fflush(stdin);
						while (ch != 13) {
							ch = _getch();
							if (ch == 8)
								cout << "\b \b";
							else {
								if (ch != 13) {
									cout << "*";
									IntroducedPassword += ch;
								}
								fflush(stdin);
							}
						}
						if (IntroducedPassword == token)
							return true;
					}
					if (IntroducedPassword != token) {
						throw LogErr("3 attempts wrong password");
					}
				}
				else
					return true;
			}
		}
	}
	file.close();
}

bool User::verifySanta()
{
	ifstream file("BDAccounts.txt");
	string line;
	istringstream iss;
	string user,pass,role;
	while (!file.eof()) {
		getline(file, line);
		iss.clear();
		iss.str(line);
		iss >> user >> pass >> role;
		if (stoi(role) == 1)
			return true;
	}
	return false;
	file.close();
}

bool User::login()
{
	cout << "Please enter your username:" << endl;
	string log_username;
	cin >> log_username;
	cout << "Please enter your password:" << endl;
	string log_password;
	log_password = takePasswordFromUser();
	if (authenticate(log_username, log_password)) {
		Logger::getInstance()->log_in_actions(username, "logged in");
		return true;
		this->connected = true;
	}
	else {
		return false;
	}
}

User::~User()
{
	username.clear();
	password.clear();
	role = -1;
	connected = false;
}
