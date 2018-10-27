#pragma once
#include <iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList()                  // default constructor
	{
		head = nullptr;
	}
	tForwardList(const tForwardList& other)
	{

	}
	tForwardList& operator=(const tForwardList &rhs)
	{
		return rhs;
	}
	~tForwardList()                 // destructor
	{
		delete head;
	}

	void push_front(const T& val)   // adds element to front (i.e. head)
	{
		Node * newNode = new Node{ val, head };
		head = newNode;
	}
	void pop_front()                // removes element from front
	{
		Node * newNode = head->next;
		delete head;
		head = newNode;
	}

	T& front()                      // returns the element at the head
	{
		return (*head).data;
	}
	const T& front() const                // returns the element at the head (const)
	{
		return (*head).data;
	}

	void remove(const T& val)       // removes all elements equal to the given value
	{
		while (head->data == val)
		{
			pop_front();
			if (head == nullptr)
			{
				return;
			}
		}
		Node * lastKnownGood = head;
		for (Node * it = lastKnownGood->next; it != nullptr;)
		{
			// always be safe to access next
			if (it->data == val)
			{
				auto next = it->next;
				delete it;
				it = next;
				continue;
			}
			lastKnownGood->next = it;
			lastKnownGood = it;
			it = it->next;
		}
		lastKnownGood->next = nullptr;
	}
};