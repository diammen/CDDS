#include<iostream>
#include <string>

#include "IBox.h"
#include "IFactory.h"
#include "Factory.h"

int main()
{
	IBox* p = NULL;
	p = Factory::GetInstance().Create("Red");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	p = Factory::GetInstance().Create("Blue");
	std::cout << "\nColor is: " << p->Color() << "\n";
	delete p;
	return 1;
}