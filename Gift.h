#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Gift
{
private:
	int id;
	string name;
	int packagingMode; //1-cutie; 2-hartie
	static int countID;
	bool isWanted;
	bool isBuilt;
public:
	Gift();
	Gift(const Gift& obj);

	void setID(int id) { this->id = id; }
	void setName(string name) { this->name = name; }
	void setBuilt(bool built) { this->isBuilt = true; }
	void setWanted(bool Wanted) { this->isWanted = Wanted; }
	void setAssemblyMode(int nr) { this->packagingMode = nr; }

	int getID() { return this->id; }
	string getName() { return this->name; }
	bool getBuilt() { return this->isBuilt; }
	bool getWanted() { return this->isWanted; }

	friend istream& operator>>(istream &in, Gift& gift) {
		cout << "GIFT NAME: ";
		in >> gift.name;
		countID++;
		gift.id = countID;
		return in;
	}
	friend ostream& operator<<(ostream& out, Gift& gift);
	friend bool operator==(Gift& objAdd1, Gift& objAdd2);
	~Gift();
};

