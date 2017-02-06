#pragma once

template <typename T>
class IList
{
public:
	IList() {};
	virtual ~IList() {};

	virtual size_t Size() = 0;
	virtual T Get(size_t) = 0;
	virtual bool Add(T) = 0;
	virtual bool Insert(T, size_t) = 0;
	virtual bool Remove(size_t) = 0;
	virtual bool CheckContent(const T*, size_t size) = 0;
};