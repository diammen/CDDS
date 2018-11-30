#include "tLinkedList.h"

int main()
{
	tForwardList<int> num;
	num.push_front(2);
	num.push_front(4);
	num.push_front(3);
	num.push_front(3);
	num.push_front(6);
	num.push_front(5);
	num.push_front(5);
	num.push_front(5);
	num.remove(5);
	num.resize(2);
	std::cout << "Look in Visual Studio project to see functionality. Expected result should be: 6, 3" << std::endl;

	tForwardList<int> test;
	test = num;

	return 0;
}