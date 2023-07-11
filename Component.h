#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Component
{
private:
	int id;
	string name;
	int dim;
	string color;
	static int countID;
public:
	Component();
	int getID() { return this->id; }
	string getName() { return this->name; }
	friend istream& operator>>(istream& in, Component& component) {
		cout << "COMPONENT NAME: ";
		in >> component.name;
		cout << "COMPONENT DIM: ";
		in >> component.dim;
		cout << "COMPONENT COLOR: ";
		in >> component.color;
		countID++;
		component.id = countID;
		cout << endl;
		return in;
	}
	friend ostream& operator<<(ostream& out, const Component& component);
	friend bool operator==(Component& objAdd1, Component& objAdd2);
	~Component();
};

