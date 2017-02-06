#pragma once

template <typename T>
class IList
{
public:
	IList() {};
	virtual ~IList() {};

	virtual size_t Size() = 0;
	virtual T Get(size_t) = 0;
	virtual size_t Add(T) = 0;
	virtual size_t Insert(T, size_t) = 0;
	virtual T Remove(size_t) = 0;
};

