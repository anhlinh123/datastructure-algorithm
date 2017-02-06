#pragma once

#include "IList.h"

template <typename T>
class ArrayList :
	public IList<T>
{
public:
	ArrayList();
	~ArrayList();

	size_t Size() override;
	T Get(size_t) override;
	size_t Add(T) override;
	size_t Insert(T, size_t) override;
	T Remove(size_t) override;

private:
	T* m_array;
	size_t m_arraySize;
	size_t m_listSize;
	size_t Grow();
	size_t Shrink();
};

