#pragma once

template <typename T>
class tVector
{
	const static size_t GROWTH_FACTOR = 2;

	T *arr;									// pointer to underlying array
	size_t arrSize;							// stores the number of elements currently used
	size_t arrCapacity;						// stores the capacity of the underlying array

public:
	tVector()								// initializes the vector's default values
	{
		arrSize = 0;
		arrCapacity = 0;
		arr = new T[arrCapacity];
	}
	~tVector()								// destroys the underlying array
	{
		delete[] arr;
	}
	tVector(const tVector &vec)
	{
		reserve(vec.arrSize);

		for (int i = 0; i < vec.arrSize; ++i)
		{
			push_back(vec.arr[i]);
		}
	}

	tVector& operator=(const tVector &vec)
	{
		reserve(vec.arrSize);

		for (int i = 0; i < vec.arrSize; ++i)
		{
			push_back(vec.arr[i]);
		}
	}

	T& operator[] (size_t index)
	{
		T retval;

		retval = at(index);

		return retval;
	}

	T *data()								// returns a pointer to the underlying array
	{
		T * arrPtr = arr;
		return arrPtr;
	}
	void reserve(size_t newCapacity)		// resizes the vector to at least this many elements
	{
		if (arrSize > newCapacity) return; // if return does not do anything, this is why
		T * newArr = new T[newCapacity];

		for (int i = 0; i < arrSize; ++i)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		arrCapacity = newCapacity;
	}
	void push_back(const T &value)  		// adds an element to the end of the vector
	{
		if (arrSize >= arrCapacity)
		{
			reserve(arrCapacity + GROWTH_FACTOR);
		}
		arr[arrSize] = value;
		arrSize++;
	}
	void pop_back()						// drops the last element of the vector
	{
		arrCapacity--;
		arrSize--;
		reserve(arrCapacity);
	}

	T &at(size_t index)					// returns the element at the given element
	{
		return arr[index];
	}

	size_t size() const					// returns current number of elements
	{
		return arrSize;
	}
	size_t capacity() const				// returns maximum number of elements we can store
	{
		return arrCapacity;
	}

	bool empty()
	{
		if (arrSize == 0)
			return true;
		return false;
	}

	void resize(size_t size)
	{
		T * newArr = new T[size];
		if (arrSize < size) reserve(size);

		for (int i = 0; i < size; ++i)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		arrCapacity = size;
	}

	void shrink_to_fit()
	{
		T * newArr = new T[arrSize];

		for (int i = 0; i < arrSize; ++i)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		arrCapacity = arrSize;
	}

	void clear()
	{
		delete[] arr;
		arrSize = arrCapacity = 0;
	}
};