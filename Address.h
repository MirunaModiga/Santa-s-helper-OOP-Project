#pragma once
#include <iostream>
#include <string>

using namespace std;

class Address
{
private:
	int id;
	string street;
	string town;
	int nrCasa;
	bool isCurrent;
	static int countID;
public:
	Address();
	int getID() { return this->id; }
	string getName() { return (this->town) +" "+ (this->street)+" " + to_string((this->nrCasa)); }
	bool getIsCurr() { return this->isCurrent; }
	void setIsCurr(bool is) { this->isCurrent = is; }
	friend istream& operator>>(istream& in, Address& address) {
		cout << "TOWN NAME: ";
		in >> address.town;
		cout << "STREET NAME: ";
		in >> address.street;
		cout << "HOUSE NUMBER: ";
		in >> address.nrCasa;
		cout << "Introduce 1 if is CURRENT and 0 otherwise: ";
		in >> address.isCurrent;
		countID++;
		address.id = countID;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Address& address);
	friend bool operator==(Address& objAdd1, Address& objAdd2);

	~Address();
};

