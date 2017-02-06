#include "ArrayList.h"
#include <assert.h>

template <typename T>
ArrayList<T>::ArrayList()
	: m_array(nullptr)
	, m_arraySize(0)
	, m_listSize(0)
{
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
size_t ArrayList<T>::Add(T t)
{
	if (m_listSize >= m_arraySize)
	{
		Grow();
	}
	assert(m_listSize < m_arraySize);
	m_arraySize[++m_listSize] = t;
	return m_listSize - 1;
}

template <typename T>
size_t ArrayList<T>::Insert(T t, size_t index)
{
	assert(index < m_listSize);
	if (m_listSize >= m_arraySize)
	{
		Grow();
	}
	assert(m_listSize < m_arraySize);

	m_listSize++;
	for (size_t i = m_listSize - 1; i > index; i--)
	{
		m_array[i] = m_array[i - 1];
	}

	m_array[index] = t;
	return index;
}

template < typename T >
T ArrayList<T>::Remove(size_t index)
{
	assert(index < m_list);
	for (size_t i = index; i < m_listSize - 1; i++)
	{
		m_array[i] = m_array[i + 1];
	}
	m_listSize--;
}
