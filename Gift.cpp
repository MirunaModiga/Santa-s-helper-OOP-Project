#include "Gift.h"
int Gift::countID = 0;

Gift::Gift()
{
	this->id = -1;
	this->isBuilt = false;
	this->isWanted = false;
	this->name = "";
	this->packagingMode = -1;
}

Gift::Gift(const Gift& obj)
{
	this->id = obj.id;
	this->isBuilt = obj.isBuilt;
	this->isWanted = obj.isWanted;
	this->name = obj.name;
	this->packagingMode = obj.packagingMode;
}

Gift::~Gift()
{
	id = -1;
	name.clear();
	isWanted = false;
	isBuilt = false;
	packagingMode = -1;
}

ostream& operator<<(ostream& out, Gift& gift)
{
	out << gift.id << " ";
	out << gift.name;
	out << " ";
	return out;
}

bool operator==(Gift& objAdd1, Gift& objAdd2)
{
	return objAdd1.name == objAdd2.name;
}
