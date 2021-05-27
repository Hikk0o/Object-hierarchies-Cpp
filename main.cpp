#include <iostream>
#include <string>
#include "Base.h"
#include "Branch.h"
#include "Root.h"
using namespace std;
int main()
{
	string name;
	cin >> name;
	Root root(name);
	Branch* parentLastBr;
	Branch* lastBr;
	string name_parent, name_child;
	bool pr = true;
	cin >> name_parent >> name_child;
	lastBr = 0;
	parentLastBr = 0;
	while (name_parent != name_child)
	{
		if (pr)
		{
			lastBr = new Branch(&root, name_child);
			pr = false;
		}
		else if (name_parent == (*lastBr).getName())
		{
			parentLastBr = lastBr;
			lastBr = new Branch(parentLastBr, name_child);
		}
		else if (name_parent == root.getName())
		{
			lastBr = new Branch(&root, name_child);
		}
		else
		{
			lastBr = new Branch(parentLastBr, name_child);
		}
		cin >> name_parent >> name_child;
	}
	cout << root.getName().c_str() << "\n";
	root.print();
	return(0);
}
