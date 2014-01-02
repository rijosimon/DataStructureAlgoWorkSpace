#ifndef _SLS_TEMP_
#define _SLS_TEMP_

#include <iostream>
#include <vector>
#include<algorithm>
#include <iterator>

template <typename ValueType>
class SList
{
public:
	//Default Constructor
	//Pre Conditions: None
	//Post Condition: _head refers to NULL and size of the list is zero
	//Strong Guarantee
	SList():_head(NULL), _size(0)
	{}
	
	//Copy Constructor - const
	//Pre Conditions: None
	//Post Condition: this doesn't point to other.
	//Strong Guarantee
	SList(const SList& other)
	{	
	
		Node *tHead = other._head;
		_head = NULL;
		while(tHead != NULL)
		{  
			insertBeg(tHead->_data);
			tHead= tHead->_next;    
		}
		
		_size = other._size;
		reverse();
	}
	
	//Copy Constructor
	//Pre Conditions: None
	//Post Condition: this doesn't point to other.
	//Strong Guarantee
	SList(SList& other)
	{
		Node *tHead = other._head;
		_head = NULL;
		while(tHead != NULL)
		{  
			insertBeg(tHead->_data);
			tHead= tHead->_next;    
		}
		
		_size = other._size;
		reverse();
	}
	
	//copy Assignment Operator
	//Pre Conditions: None
	//Post Condition: this doesn't point to other.
	//Strong Guarantee
	SList & operator=(const SList other)
	{
		swap(other);
		return *this;
	}
	
	//Destructor
	//Pre Conditions: None
	//Post Condition: Nodes in the list are deleted, _head is deleted.
	//Strong Guarantee
	~SList()
	{
		if(_head)
		{
			delete _head;
		}
	}
	
	//Function - Insert node to start of list.
	//Pre Conditions: None
	//Post Condition: _head point to a new valid node.
	//Does not Throw
	void insertBeg(const ValueType & data)
	{
		_head = new Node(data,_head);
		++_size;
	}
	
	//Function - Swap list.
	//Pre Conditions: None
	//Post Condition: Values deeply copied as part of swapping values between the lists.
	//Strong Guarantee
	void swap(SList slist)
	{
		std::swap(slist._head,_head);
		std::swap(slist._size,_size);
	}
	
	//Function - size() const
	//Pre Conditions: None
	//Post Condition: returns _size
	//Strong Guarantee
	std::size_t size() const
	{ return _size;}
	
	//Function - size()
	//Pre Conditions: None
	//Post Condition: returns _size
	//Strong Guarantee
	std::size_t size()
	{ return _size;}
	
	//function - reverse()
	//Pre Conditions: List ends with node that points to its next as NULL.
	//Post Condition: The pointers in the list are reversed and head points to what was initially the first element.
	//Basic Guarantee
	void reverse()
	{
		struct Node *save = NULL;
		
		while (_head != NULL)
			{
				struct Node *t = _head;
				_head = _head->_next; 
				t->_next = save;          
				save = t;
			}
			_head = save;
	}
	
	//function - read()
	//Pre Conditions: begin and end should represent a valid list.
	//Post Condition: List contains the elements of the list represented by begin and end.
	//Basic Guarantee
	template <typename InputIterator>
	void read(InputIterator begin, InputIterator end) 
	{
		SList t;
    
		while (begin!=end)
		{
			ValueType val = *begin++;
			t.insertBeg(val);
		}
		t.reverse();
		swap(t);
	}
	
	//function - write()
	//Pre Conditions: begin is a valid iterator.
	//Post Condition: None
	//Basic Guarantee
	template <typename OutputIterator>
	void write(OutputIterator begin) const
	{
		Node *copyHead = _head;
		while(copyHead != NULL)
		{
			ValueType val = copyHead->_data;
			copyHead = copyHead->_next;
			*begin++=val;
		}
	}
	
	//function - topData()
	//Pre Conditions: list has atleast one element
	//Post Condition: returns ValueType reference
	//Basic Guarantee
	ValueType & topData()
	{	
		return _head->_data;
	}

	//function - topData() const
	//Pre Conditions: list has atleast one element
	//Post Condition: returns ValueType reference
	//Basic Guarantee	
	ValueType & topData() const
	{	
		return _head->_data;
	}
	
	//function - removeBed()
	//Pre Conditions: None
	//Post Condition: removes top node of the list.
	//Basic Guarantee	
	void removeBeg()
	{
		if (_head)
		{    
			struct Node *t = _head;
			_head = _head->_next;
			t->_next = NULL;
			delete t;
			--_size;
		}
	}
	
	// struct Node
	// Linked List node, with client-specified value type
	// Invariants:
	//     Either _next is NULL, or _next points to an Node,
	//      allocated with new, owned by *this.
	// Requirements on Types:
	//     ValueType must have a copy ctor and a dctor.
	struct Node
	{
		ValueType _data;
		Node * _next;
	
	Node():_data(), _next(NULL)
    {}
	
	Node(const ValueType data, Node * next):_data(data), _next(next)
	{}
	
	~Node()
    { 	
	if(_next)
		{
			delete _next;
		} 
	}
	};
	
	Node *_head=NULL;
	std::size_t _size;
	
};

#endif