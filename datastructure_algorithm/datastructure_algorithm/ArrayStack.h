#pragma once

#include "IStack.h"

template <typename T>
class ArrayStack : 
	public IStack<T>
{
public:
	ArrayStack();
	ArrayStack(size_t size, const T* data);
	~ArrayStack();

	size_t Count() override;
	bool Push(T t) override;
	T Pop() override;

private:
	T* m_array;
	size_t m_arraySize;
	size_t m_stackSize;

	bool Grow();
	bool Shrink();
};

template <typename T>
ArrayStack<T>::ArrayStack()
	: m_array(nullptr)
	, m_arraySize(0)
	, m_stackSize(0)
{
}

template <typename T>
ArrayStack<T>::ArrayStack(size_t size, const T* data)
	: m_arraySize(0)
	, m_stackSize(size)
{
	Grow();
	memcpy(m_array, data, size);
}

template <typename T>
size_t ArrayStack<T>::Count()
{
	return m_stackSize;
}

template <typename T>
bool ArrayStack<T>::Push(T t)
{
	if (Grow())
	{
		m_array[m_stackSize++] = t;
		return true;
	}
	return false;
}

template <typename T>
T ArrayStack<T>::Pop()
{
	assert(m_stackSize > 0);
	T t = m_array[--m_stackSize];
	Shrink();
	return t;
}

template <typename T>
bool ArrayStack<T>::Grow()
{
	if (m_stackSize >= m_arraySize)
	{
		while (m_stackSize >= m_arraySize)
		{
			m_arraySize = m_arraySize ? m_arraySize * 2 : 1;
		}

		T* newArray = new T[m_arraySize];
		if (newArray)
		{
			if (m_array)
			{
				memcpy(newArray, m_array, m_stackSize * sizeof(T));
				delete[] m_array;
			}
			m_array = newArray;
		}
		else
		{
			return false;
		}
	}
	return true;
}

template <typename T>
bool ArrayStack<T>::Shrink()
{
	return true;
}