#ifndef DA3_H_
#define DA3_H_

#include <iostream>   // for std::ostream
#include <string>     // for std::string
#include <stdexcept>
#include <algorithm>


// *************************************************************** // *
// Begin DO-NOT-CHANGE section                                     // *
// Do not alter the lines below                                    // *
// *************************************************************** // *
                                                                   // *
                                                                   // *
// struct LLNode                                                   // *
// Linked List node, with client-specified value type              // *
// Invariants:                                                     // *
//     Either next_ is NULL, or next_ points to an LLNode,         // *
//      allocated with new, owned by *this.                        // *
template <typename ValueType>                                      // *
struct LLNode {                                                    // *
    ValueType data_;  // Data for this node                        // *
    LLNode * next_;   // Ptr to next node, or NULL if none         // *
                                                                   // *
    // The following simplify creation & destruction               // *
                                                                   // *
    // 1- & 2-param ctor                                           // *
    // Pre:                                                        // *
    //     theNext, if passed, is either NULL,                     // *
    //      or else it points to an LLNode, allocated with new,    // *
    //      with ownership transferred to *this.                   // *
    // Post:                                                       // *
    //     data_ == theData.                                       // *
    //     If next_ passed, then next_ == theNext.                 // *
    //      otherwise, next_ is NULL.                              // *
    explicit LLNode(const ValueType & theData,                     // *
                    LLNode * theNext = NULL)                       // *
        :data_(theData), next_(theNext)                            // *
    {}                                                             // *
                                                                   // *
    // dctor                                                       // *
    // Pre: None.                                                  // *
    // Post: None. (next_ delete'd)                                // *
    ~LLNode()                                                      // *
    { delete next_; }                                              // *
};                                                                 // *



// size
// Given ptr to LLNode, return its size (number of nodes).
// Pre:
//     head is ptr to NULL-terminated Linked List, or NULL.
// Post:
//     Return is size of list, or 0 if head is NULL.
// Requirements on Types:
//     ValType must have a copy ctor and a dctor.
//     NOTE: These requirements are inherited from struct LLNode;
//      we do not use any member functions of ValueType here.
// 

template <typename T>
std::size_t size(const LLNode<T> * head)
{
	const LLNode<T> *temp = head;

std::size_t count = 0;
while(temp != 0)
   {
   ++count;
   temp = temp->next_;
   }
return count;
}
                                                                   
// *************************************************************** // *
// listItem
// Given ptr to LLNode and an int indec, return corresponding element in list indexed by index-1 th element.
// Pre:
//     head is ptr to NULL-terminated Linked List, or NULL.
// Post:
//     Return is the data_ of the node at the correct index.
// Requirements on Types:
//     T must have a copy ctor and a dctor.
//     NOTE: These requirements are inherited from struct LLNode.
//      
// *************************************************************** // *


template <typename T>
T listItem(const LLNode<T> * head,
           int index)
{
	T returnVal = 0;
	std::size_t llSize = size(head);
	std::size_t indexS = index;
		if(indexS < 0 || indexS >= llSize)
		{
			throw std::out_of_range("Out of Range in the Linked List");
		}
		else
		{
			int i =0;
			while (i < index)
			{
				head = head->next_;
				i++;
			}
			returnVal = head->data_;
		}
	return returnVal;
}

// *************************************************************** // *
// didItThrow
// Given reference to a function and a boolean sets boolen true of function throws and re-throws else sets boolean false.
// Pre:
//    f points to a valid function which may or may not throw or return, with no parameters.
//
// Post:
//     
// Requirements on Types:
//     Throw type from function passed is std::runtime_error or int for proper re-throw.
//      
// *************************************************************** // *

template <typename Func>
void didItThrow(Func f,
                bool & threw)
{
	threw = false;
	try{
		f();
	}
	catch (const std::runtime_error& ex) {
	    threw = true;
	    throw ex;
	} catch (const int& ex) {
	    threw = true;
	    throw ex;
	} catch (...) {
	    threw = true;
	}
}

// *************************************************************** // *
// printRange
// Given iterator to the first and last element of a range of elements and reference to a stream objects prints every element of the 
// range to the stream with a newline following every element.
// Pre:
//     last should come after first
// Post:
//     
//      
// *************************************************************** // *


template <typename FDIter>
void printRange(FDIter first,
                FDIter last,
                std::ostream & theStream)
{

    FDIter iterPointer = first;
    for (; iterPointer!=last; iterPointer++)
    	theStream<<*iterPointer<<std::endl;
}

// *************************************************************** // *
// rangesEqual
// Given iterator to the first and last element of a range and a third iterator to the first element of another range.
// Uses a function from STL to achieve this.
// Pre:
//     Iterators are valid.
// Post:
//     Return is a bool value.
//      
// *************************************************************** // *


template <typename FDIter>
bool rangesEqual(FDIter first1,
                 FDIter last1,
                 FDIter first2)
{
	return std::equal(first1, last1, first2);
}

// *************************************************************** // *
// collatz
// Counts the number of steps required to perform a custom operation using recursive calls.
// Pre:
//     
// Post:
//      
// *************************************************************** // *


int collatz(int n);

#endif /*DA3_H_*/
