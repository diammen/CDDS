#include "tLinkedList.h"

int main()
{
	tForwardList<int> num;
	num.push_front(2);
	num.push_front(4);
	num.push_front(5);
	num.push_front(5);
	num.push_front(5);
	num.remove(5);

	return 0;
}