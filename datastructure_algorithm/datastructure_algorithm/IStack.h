#pragma once

template <typename T>
class IStack
{
public:
	virtual ~IStack() {};

	virtual size_t Count() = 0;
	virtual bool Push(T t) = 0;
	virtual T Pop() = 0;
};