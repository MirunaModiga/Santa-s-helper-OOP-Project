#include "Component.h"
int Component::countID = 0;

Component::Component()
{
	this->id = -1;
	this->name = "";
	this->dim = -1;
	this->color = "";
}

Component::~Component()
{
	id = -1;
	name.clear();
	dim = -1;
	color.clear();
}

ostream& operator<<(ostream& out, const Component& component)
{
	out << component.id << " " << component.name << " " << component.dim << " " << component.color << endl;
	return out;
}

bool operator==(Component& objAdd1, Component& objAdd2)
{
	return ((objAdd1.name == objAdd2.name) && (objAdd1.color == objAdd2.color) && (objAdd1.dim == objAdd2.dim));
}
