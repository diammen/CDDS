#pragma once
#include <iostream>

template<typename T>
class tForwardList
{
	struct Node
	{
		T data;                     // data for the element stored
		Node * next = nullptr;                // pointer to node following this node
	};

	Node * head;                    // pointer to head of linked list

public:
	tForwardList()                  // default constructor
	{
		head = nullptr;
	}
	tForwardList(const tForwardList& other)
	{
		for (Node * it = head; it != nullptr;)
		{
			it = other.head;
			it = it->next;
		}
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

	bool empty() const
	{
		if (head == nullptr)
		{
			return true;
		}
		return false;
	}
	void clear()
	{
		Node * current = head;
		Node * next;
		while (current != NULL)
		{
			next = head->next;
			free(current);
			current = next;
		}
	}
	void resize(size_t newSize)
	{
		Node * current = head;
		if (count() < newSize)
		{
			for (int i = 0; i < newSize; ++i)
			{
				if (current->next != nullptr)
					current = current->next;
				else
				{
					current->next = new Node;
					current = current->next;
				}
			}
			head = current;
		}
		else
		{
			head = current;
			for (int i = 0; i < newSize - 1; ++i)
			{
				current = current->next;
			}
			Node * tempHead = current->next;
			Node * tempNext = tempHead->next;
			current->next = nullptr;
			while (tempHead->next != nullptr)
			{
				delete tempHead;
				tempHead = tempNext;
				tempNext = tempHead->next;
			}
			tempHead->next = nullptr;
		}
	}
	int count()
	{
		int counter = 0;
		for (auto i = begin(); i != end(); ++i)
			counter++;
		return counter;
	}

	class iterator
	{
		Node * cur;                                 // current node being operated upon

	public:
		iterator() {}
		iterator(Node * start)
		{
			cur = start;
		}
		bool operator==(const iterator& rhs) const  // returns true if the iterator points to the same node
		{
			return cur == rhs.cur;
		};
		bool operator!=(const iterator& rhs) const  // returns false if the iterator does not point to the same node
		{
			return cur != rhs.cur;
		};
		T& operator*() const                        // returns a reference to the element pointed to by the current node
		{
			return cur->data;
		};
		iterator& operator++()                      // pre-increment (returns a reference to this iterator after it is incremented)
		{
			cur = cur->next;
			return (*this);
		};
		iterator operator++(int)                    // post-increment (returns an iterator to current node while incrementing the existing iterator)
		{
			iterator newIterator;
			newIterator.cur = cur;
			++cur;
			return newIterator;
		};
		void goToBegin(Node* _head)
		{
			cur = _head;
		};
	};

	iterator begin()
	{
		return iterator(head);
	};
	iterator end()
	{
		return iterator(nullptr);
	};
};