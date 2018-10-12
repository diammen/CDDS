#pragma once
#include <string>
using std::string;

class Potion
{
public:
	string name;
	int HPModifier;
	int quality;
	int useByDate;

	// ctors & dtors
	Potion();
	~Potion();
};