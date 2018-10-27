#pragma once

#include "tVector.h"

template <typename T>
class tQueue
{
	tVector<T> vec;							// contains the data for a queue

public:
	tQueue()	                            // default initializes the queue
	{

	}
	tQueue(size_t count, const T& value)	// constructs a queue with the given number of elements 
	{										// each element is initialized by copying the given value
		for (int i = 0; i < count; ++i)
		{
			vec.push_back(value);
		}
	}
	void push(const T& value)				// adds an element to the top of the Queue
	{
		vec.push_back(value);
	}
	void pop()								// drops the top-most element of the Queue
	{
		vec.pop_front();
	}
	void clear()
	{
		vec.clear();
	}

	T& front()								// returns the front-most element
	{
		return vec[0];
	}
	const T& front() const
	{
		return vec[vec.size() - 1];
	}
	T& back()								// returns the back-most element
	{
		return vec[0];
	}
	const T& back() const
	{
		return vec[0];
	}

	size_t size() const						// returns current number of elements
	{
		return vec.size();
	}

	bool empty() const
	{
		return !vec.size();
	}
};