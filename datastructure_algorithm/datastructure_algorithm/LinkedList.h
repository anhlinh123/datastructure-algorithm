#pragma once

#include "IList.h"
#include <assert.h>

template <typename T>
struct LinkedNode
{
	LinkedNode(const T& t) : data(t), next(nullptr) {};
	T data;
	LinkedNode<T>* next;
};

template <typename T>
class LinkedList : 
	public IList < T >
{
public:
	LinkedList();
	LinkedList(size_t size, T* arrayT);
	~LinkedList();

	size_t Size() override;
	T Get(size_t) override;
	bool Add(T) override;
	bool Insert(T, size_t) override;
	bool Remove(size_t) override;
	bool CheckContent(const T*, size_t size) override;

private:
	LinkedNode<T>* m_root;
	size_t m_size;
};

template <typename T>
LinkedList<T>::LinkedList()
	: m_root(nullptr)
	, m_size(0)
{
}

template <typename T>
LinkedList<T>::LinkedList(size_t size, T* arrayT)
	: m_size(size)
{
	if (size > 0)
	{
		m_root = new LinkedNode<T>(arrayT[0]);
		LinkedNode<T>* node = m_root;
		for (size_t i = 1; i < size; i++)
		{
			LinkedNode<T>* next = new LinkedNode<T>(arrayT[i]);
			node->next = next;
			node = next;
		}
	}
	else
	{
		m_root = nullptr;
	}
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	LinkedNode<T>* node = m_root;
	for (size_t i = 0; i < m_size; i++)
	{
		assert(node);
		LinkedNode<T>* next = node->next;
		delete node;
		node = next;
	}
	assert(node == nullptr);
	m_root = nullptr;
	m_size = 0;
}

template <typename T>
size_t LinkedList<T>::Size()
{
	return m_size;
}

template <typename T>
T LinkedList<T>::Get(size_t index)
{
	LinkedNode<T>* node = m_root;
	for (size_t i = 0; i <= index; i++)
	{
		if (node)
		{
			node = node->next;
		}
		else
		{
			break;
		}
	}
	assert(node);
	return node->data;
}

template <typename T>
bool LinkedList<T>::Add(T t)
{
	if (!m_root)
	{
		m_root = new LinkedNode<T>(t);
		m_size = 1;
	}
	else
	{
		LinkedNode<T>* node = m_root;
		while (node->next)
		{
			node = node->next;
		}
		node->next = new LinkedNode<T>(t);
		m_size++;
	}
	return true;
}

template <typename T>
bool LinkedList<T>::Insert(T t, size_t index)
{
	if (index <= m_size)
	{
		LinkedNode<T>* node = m_root;
		if (index == 0)
		{
			m_root = new LinkedNode<T>(t);
			m_root->next = node;
		}
		else
		{
			for (size_t i = 0; i + 1 < index; i++)
			{
				assert(node);
				node = node->next;
			}

			assert(node);
			LinkedNode<T>* next = node->next;
			node->next = new LinkedNode<T>(t);
			node->next->next = next;
		}
		m_size++;
		return true;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::Remove(size_t index)
{
	if (index < m_size)
	{
		LinkedNode<T>* node = m_root;
		for (size_t i = 0; i + 1 < index; i++)
		{
			assert(node);
			node = node->next;
		}

		assert(node);
		LinkedNode<T>* next = node->next;
		if (index == 0)
		{
			m_root = next;
		}
		else
		{
			node->next = next->next;
			node = next;
		}
		delete node;
		m_size--;
	}

	return false;
}

template <typename T>
bool LinkedList<T>::CheckContent(const T* array, size_t size)
{
	if (size == m_size)
	{
		LinkedNode<T>* node = m_root;
		for (size_t i = 0; i < size; i++)
		{
			if (array[i] != node->data)
			{
				return false;
			}
			assert(node);
			node = node->next;
		}
		return true;
	}
	return false;
}