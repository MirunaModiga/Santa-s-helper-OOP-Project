#include "Address.h"
int Address::countID = 0;

ostream& operator<<(ostream& out, const Address& address)
{
	out << address.id<< " "<< address.town<< " Strada "<<address.street<<" "<<address.nrCasa<<" ";
	if (address.isCurrent)
		out << "[current address]";
	return out;
}

bool operator==(Address& objAdd1, Address& objAdd2)
{
	return (objAdd1.town == objAdd2.town)&&(objAdd1.street==objAdd2.street)&&(objAdd1.nrCasa==objAdd2.nrCasa);
}

Address::Address()
{
	this->id = -1;
	this->isCurrent = false;
	this->town = "";
	this->street = "";
	this->nrCasa = -1;
}

Address::~Address()
{
	id = -1; 
	town.clear(); 
	street.clear();
	nrCasa = -1;
	isCurrent = false;
}
