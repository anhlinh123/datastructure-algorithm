#pragma once

#include "IList.h"
#include <assert.h>
#include <string.h>

template <typename T>
class ArrayList :
	public IList<T>
{
public:
	ArrayList();
	ArrayList(size_t size, T* arrayT);
	~ArrayList();

	size_t Size() override;
	T Get(size_t) override;
	bool Add(T) override;
	bool Insert(T, size_t) override;
	bool Remove(size_t) override;
	bool CheckContent(const T* array, size_t size) override;

private:
	T* m_array;
	size_t m_arraySize;
	size_t m_listSize;
	bool Grow();
	bool Shrink();
};

template <typename T>
ArrayList<T>::ArrayList()
	: m_array(nullptr)
	, m_arraySize(0)
	, m_listSize(0)
{
}

template <typename T>
ArrayList<T>::ArrayList(size_t size, T* arrayT)
	: m_arraySize(0)
	, m_array(nullptr)
	, m_listSize(size)
{
	Grow();
	memcpy(m_array, arrayT, size * sizeof(T));
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	if (m_array)
	{
		delete[] m_array;
		m_array = nullptr;
	}
	m_arraySize = 0;
	m_listSize = 0;
}

template <typename T>
size_t ArrayList<T>::Size()
{
	return m_listSize;
}

template <typename T>
T ArrayList<T>::Get(size_t index)
{
	assert(index < m_listSize);
	return m_array[index];
}

template <typename T>
bool ArrayList<T>::Add(T t)
{
	if (Grow())
	{
		m_array[m_listSize++] = t;
		return true;
	}
	return false;
}

template <typename T>
bool ArrayList<T>::Insert(T t, size_t index)
{
	if (index <= m_listSize && Grow())
	{
		m_listSize++;
		for (size_t i = m_listSize - 1; i > index; i--)
		{
			m_array[i] = m_array[i - 1];
		}
		m_array[index] = t;
		return true;
	}
	return false;
}

template <typename T>
bool ArrayList<T>::Remove(size_t index)
{
	if (index < m_listSize)

	{
		for (size_t i = index; i < m_listSize - 1; i++)
		{
			m_array[i] = m_array[i + 1];
		}
		m_listSize--;
		Shrink();
		return true;
	}
	return false;
}

template <typename T>
bool ArrayList<T>::CheckContent(const T* array, size_t size)
{
	if (size == m_listSize)
	{
		return memcmp(m_array, array, size * sizeof(T)) == 0;
	}
	return false;
}

template <typename T>
bool ArrayList<T>::Grow()
{
	if (m_listSize >= m_arraySize)
	{
		while (m_listSize >= m_arraySize)
		{
			m_arraySize = m_arraySize ? m_arraySize * 2 : 1;
		}

		T* newArray = new T[m_arraySize];
		if (newArray)
		{
			if (m_array)
			{
				memcpy(newArray, m_array, m_listSize * sizeof(T));
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
bool ArrayList<T>::Shrink()
{
	return true;
}