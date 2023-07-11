#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Gift.h"
using namespace std;

class Child
{
private:
	int id;
	string name;
	string surname;
	string date_of_birth;
	bool behavior;
	static int countID;
	vector<Gift*>ReceivedGifts_;
public:
	Child();
	bool getBehavior() { return this->behavior; }
	int getID() { return this->id; }
	string getName() { return this->name; }
	string getSurname() { return this->surname; }
	void addReceivedGifts(Gift* gift) { this->ReceivedGifts_.push_back(gift); }

	friend istream& operator>>(istream& in, Child& child){
		cout << "CHILD NAME: ";
		in >> child.name;
		cout << "CHILD SURNAME: ";
		in >> child.surname;
	start:
		cout << "DATE OF BIRTH (zz/ll/aa): ";
		for (int j = 0; j < 2; j++) {
			for (int i = 0; i < 2; i++) {
				fflush(stdin);
				char ch;
				ch = _getch();
				/*if (ch == 8)
					cout << "\b \b";*/
				cout << ch;
				child.date_of_birth += ch;
				if (isalpha(ch))
				{
					cout << "\nInvalid data!Try again...\n";
					goto start;
				}
			}
			cout << "/";
			child.date_of_birth += "/";
		}
		for (int i = 0; i < 4; i++) {
			fflush(stdin);
			char ch;
			ch = _getch();
			cout << ch;
			child.date_of_birth += ch;
			if (isalpha(ch))
			{
				cout << "\nInvalid data!Try again!\n";
				goto start;
			}
		}
	start1:
		cout << "\nCHILD BEHAVIOR(good or evil): ";
		string b;

		in >> b;
		if (b == "good")
			child.behavior = true;
		else {
			if (b == "evil")
				child.behavior = false;
			else {
				cout << "Invalid data!Try again!\n";
				goto start1;
			}
		}
		countID++;
		child.id = countID;

		return in;
	}
	friend ostream& operator<<(ostream& out, const Child& child);
	~Child();
};
