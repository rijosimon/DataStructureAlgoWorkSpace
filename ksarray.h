// CS 311 HW 2 - Assignment 2
// Date: 02/18/2013
// Author: Rijo S Simon
// Kinda-Smart Array Class

#ifndef KSARRAY_H_
#define KSARRAY_H_

#include <iostream>


template <typename ValueType>
class KSArray
{
public:
	
	typedef ValueType value_type;
	typedef std::size_t size_type;
	
	KSArray()
	{
		_s = 10;
		_v = new ValueType[10];
	}
	KSArray(ValueType v, std::size_t size)
	{
		_s = size;
		_v = new ValueType[size];
		std::size_t i =0;
		while(i<size)
		{
			_v[i] = v;
			i++;
		}
		
	}
	
	KSArray(const KSArray & ksa)
	{
		_s = ksa.size();
		_v = new ValueType(ksa.size());
		std::size_t i =0;
				while(i < ksa.size())
				{
					_v[i] = ksa[i];
					i++;
				}
	}
	
	KSArray & operator=(const KSArray & ksa)
	{
		
		if(this != &ksa)
		{
			
			delete [] _v;
			_s = ksa.size();
			_v = new ValueType[ksa.size()];
			std::size_t i =0;
						while(i < ksa.size())
						{
							_v[i] = ksa[i];
								i++;
						}
		}
		
		return *this;
	}
	~KSArray()
	{
		delete [] _v;
	}
	
	ValueType & operator[](int n)
		{
			
			return *(_v + n);
		}
	
	ValueType & operator[](int n) const
	{
		
		return *(_v + n);
	}
	std::size_t size() const
	{
		return _s;
	}
	
	ValueType * begin()
	{
		return _v;
		
	}
	ValueType * end()
	{
		
		return (_v+_s);
	}
	ValueType * begin() const
	{
		
		return _v;
	}
	ValueType * end() const
	{
		return (_v+_s);
	}
	
private:
	
	value_type * _v;
	size_type _s;
	
};

template <typename ValueType>
bool operator==(const KSArray<ValueType> & ksal, const KSArray<ValueType> &ksar)
{
	if(ksal.size() != ksar.size())
	{
		return false;
	}
	std::size_t i =0;
			while(i<ksal.size())
			{
				if(ksal[i]!=ksar[i])
					return false;
				i++;
			}
			return true;
}

template <typename ValueType>
bool operator!=(const KSArray<ValueType> & ksal, const KSArray<ValueType> & ksar)
{
	return !(ksal==ksar);
}

template <typename ValueType>
bool operator<(const KSArray<ValueType> & ksal, const KSArray<ValueType> & ksar)
{
	if(ksal == ksar)
		return false;
	if(ksal.size() > ksar.size())
		return false;
	std::size_t i =0;
				while(i<ksal.size())
				{
					if(ksal[i]>ksar[i])
						return false;
					i++;
				}
		return true;
}
template <typename ValueType>
bool operator>(const KSArray<ValueType> & ksal, const KSArray<ValueType> & ksar)
{
	return (!(ksal < ksar) && !(ksal == ksar));
}
template <typename ValueType>
bool operator<=(const KSArray<ValueType> & ksal, const KSArray<ValueType> & ksar)
{
	return !(ksal > ksar);
}
template <typename ValueType>
bool operator>=(const KSArray<ValueType> & ksal, const KSArray<ValueType> & ksar)
{
	return !(ksal < ksar);
}
#endif /*KSARRAY_H_*/
