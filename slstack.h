#ifndef _SLST_TEMP_
#define _SLST_TEMP_

#include <iostream>
#include "slist.h"

template <typename ValueType>
class SLStack
{

public:
	
	//Function - empty()
	//Pre Conditions: None
	//Post Condition: returns TRUE or FALSE
	//Strong Guarantee
	bool empty()
	{
		return _list.size() == 0;
	}
	
	//Function - empty() const
	//Pre Conditions: None
	//Post Condition: returns TRUE or FALSE
	//Strong Guarantee
	bool empty() const
	{
		return _list.size() == 0;
	}
	
	//Function - top()
	//Pre Conditions: None
	//Post Condition: returns value of the top node in the list.
	//Strong Guarantee
	ValueType & top()
	{
		return _list.topData();
	}

	//Function - top() - const
	//Pre Conditions: None
	//Post Condition: returns value of the top node in the list.
	//Strong Guarantee
	ValueType & top() const
	{
		return _list.topData();
	}
	
	//Function - push()
	//Pre Conditions: None
	//Post Condition: insert data in a new node to the top of the list.
	//Strong Guarantee
	void push(ValueType v)
	{
		_list.insertBeg(v);
	}
	
	//Function - pop()
	//Pre Conditions: None
	//Post Condition: remove the top node on the list.
	//Strong Guarantee
	void pop()
	{
		_list.removeBeg();
	}

	private:
	
	SList<ValueType> _list;	
};

#endif