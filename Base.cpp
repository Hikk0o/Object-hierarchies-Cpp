#include <iostream>
#include "Base.h"

using namespace std;
Base::Base(Base* parent)
{
	this->parent = parent;
	if (parent != 0)
		parent->children.push_back(this);
}
Base::Base(Base* parent, string name)
{
	this->parent = parent;
	this->name = name;
	if (parent != 0)
		parent->children.push_back(this);
}
void Base::setName(string name)
{
	this->name = name;
}
string Base::getName()
{
	return name;
}
void Base::print()
{
	cout << this->getName().c_str();
	for (int i = 0; i < children.size(); i++)
		cout << " " << children[i]->getName().c_str();
	for (int i = 0; i < children.size(); i++)
	{
		if (children[i]->children.size() > 0)
		{
			cout << "\n";
			children[i]->print();
		}
	}
}
Base::~Base()
{
	for (int i = 0; i < children.size(); i++)
		delete children[i];
}
