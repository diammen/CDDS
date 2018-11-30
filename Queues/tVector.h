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
		delete arr;
	}
	tVector(const tVector &vec)
	{
		reserve(vec.arrSize);

		for (size_t i = 0; i < vec.arrSize; ++i)
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

		return *this;
	}

	T& operator[] (size_t index)
	{
		return at(index);
	}

	T *data()								// returns a pointer to the underlying array
	{
		T * arrPtr = arr;
		return arrPtr;
	}
	void reserve(size_t newCapacity)		// resizes the vector to at least this many elements
	{
		if (arrCapacity > newCapacity) return; // exit early if we don't actually need to grow
		T * newArr = new T[newCapacity];

		for (size_t i = 0; i < arrSize; ++i)
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
		arr[arrSize++] = value;
	}
	void pop_back()						// drops the last element of the vector
	{
		if (arrCapacity <= 0) return;
		arrSize--;
		reserve(arrSize);
	}

	void pop_front()					// drops the first element of the vector
	{
		for (size_t i = 1; i < arrSize; ++i)
		{
			arr[i] = arr[i - 1];
		}
		arrSize--;
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
		return !arrSize;
	}

	void resize(size_t size)
	{
		reserve(size);

		if (size < arrSize)
		{
			arrSize = size;
		}
		else
		{
			for (size_t i = 0; i < size; ++i)
			{
				push_back(T());
			}
		}
	}

	void shrink_to_fit()
	{
		if (arrSize == arrCapacity) { return; }

		T * newArr = new T[arrSize];

		for (size_t i = 0; i < arrSize; ++i)
		{
			newArr[i] = arr[i];
		}
		delete[] arr;
		arr = newArr;
		arrCapacity = arrSize;
	}

	void clear()
	{
		arrSize = arrCapacity = 0;
	}
};