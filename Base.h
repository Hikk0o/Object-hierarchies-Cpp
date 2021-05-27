#ifndef BASE_H
#define BASE_H
#include <vector>
#include <string>
using namespace std;
class Base
{
private:
	string name;
	Base* parent;
	vector <Base*> children;


public:
	Base(Base* parent);
	Base(Base* parent, string name);
	void setName(string name);
	string getName();
	void print();
	~Base();
};
#endif
