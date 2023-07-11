#include "Child.h"
int Child::countID = 0;

Child::Child()
{
	this->id = -1;
	this->name = "";
	this->surname = "";
	this->date_of_birth = "";
	this->behavior = false;
}

Child::~Child()
{
	id = -1;
	name.clear();
	surname.clear();
	date_of_birth.clear();
	behavior = false;
	ReceivedGifts_.clear();
}

ostream& operator<<(ostream& out, const Child& child)
{
	out << child.id << " "<< child.name<< " "<< child.surname<< " "<< child.date_of_birth<< " ";
	if (child.behavior)
		out << "good\n";
	else
		out << "evil\n";
	return out;
}
