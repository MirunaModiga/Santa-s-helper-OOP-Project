#pragma once
#include <iostream>
#include <list>
#include <iterator>

#include "User.h"
#include "Child.h"
#include "Address.h"
#include "Component.h"
#include "TableAddressChild.h"
#include "TableGiftChild.h"

#include "ConcreteGiftBuilder.h"
#include "DirectorGiftBuilder.h"
#include "WorkshopErr.h"
#include "AppErr.h"

using namespace std;

class BD
{
private:
	static BD* instance;
	BD() {}
	BD(const BD& other) {}
	~BD();

	list<Child*>children_;
	list<Gift*>gifts_;
	list<Address*>addresses_;
	list<Component*>components_;
	list<TableAddressChild*>addresses_children_;
	list<TableGiftChild*>gifts_children_;
	list<TableGiftComponent*>components_gift_;

public:
	static BD* getInstance();
	static void destroyInstance();

	void getByID(string username,int id);
	void buildGift(int id);
	void sendGift();
	void Create(string filename, list<Child*>List);

	template<typename T>
	int findInList(const list<T*>& List, T* obj);

	template<typename T>
	void Create(string filename,list<T*>& List);

	void Read(string filename);

	template<typename T>
	void Update(string filename,list<T*>& List);

	template<typename T>
	void Delete(string filename,list<T*>& List);
};

template<typename T>
inline int BD::findInList(const list<T*>& List, T* obj)
{
	for (auto find = List.begin(); find != List.end(); find++) {
		if (**find == *obj)
			return (*find)->getID();
	}
	return -1;
}

template<typename T>
inline void BD::Create(string filename,list<T*>&List)
{
	T* obj = new T();
	cin >> *obj;
	if (findInList(List, obj)==-1) {
		List.push_back(obj);
	}
	fstream file;
	file.open(filename, ios::app);
	file << *obj << endl;
	file.close();
}

template<typename T>
inline void BD::Update(string filename,list<T*>& List)
{
	Read(filename);
	cout << "Update list element: Introduce name data: ";
	string name;
	cin >>name;
	auto match = [name](T* obj) { return obj->getName() == name;  };
	auto i = find_if(List.begin(), List.end(), match);
	if (i == List.end())
		throw WorkshopErr("This name doesn't exist in the database");

	cin >> **i;
	fstream file;
	file.open(filename , ios::out | ios::trunc);
	file.close();

	file.open(filename, ios::app);
	for (auto it = List.begin(); it != List.end(); it++)
		file << **it;
	file.close();
}

template<typename T>
inline void BD::Delete(string filename,list<T*>& List)
{
	Read(filename);
	cout << "Delete list element: Introduce name data: ";
	string name;
	cin >> name;
	auto match = [name](T* obj) { return obj->getName() == name;  };
	auto i = find_if(List.begin(), List.end(), match);
	if (i == List.end())
		throw WorkshopErr("This name doesn't exist in the database");
	List.erase(i);

	fstream file;
	file.open(filename, ios::out | ios::trunc);
	file.close();

	file.open(filename, ios::app);
	for (auto it = List.begin(); it != List.end(); it++)
		file << **it;
	file.close();
}
