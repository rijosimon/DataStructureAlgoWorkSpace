/*
 * TSmArray.h
 *
 *  Created on: Mar 22, 2010
 *  Author: Rijo Simon
 */

#ifndef TSmArray_H_
#define TSmArray_H_

#include <iostream>
#include <stdlib.h>
#include <cstdlib> //for std::size_t
#include <algorithm>
using std::size_t;

// Invariants:
// _capacity >= _size >= 0
// _data points to an array of int, allocated with new [], owned by *this, holding _capacity ints.
// (unless _capacity==0 in which case _data may be NULL)
template <typename ValueType>
class TSmArray
{
public:
   typedef size_t size_type;
   typedef ValueType value_type;
   typedef value_type * iterator;
   typedef const value_type * const_iterator;

   //Default Constructor
   
   TSmArray()
   {
   }
   
   // 1 - Parameter Constructor
   
   TSmArray(size_type size)
   {
		
   }
   
   // Copy Constructor
   
   TSmArray(const TSmArray& other)
   {
   
		
   
	}
   // Destructor
   
   ~TSmArray()
   {
   }
   
   // Copy Assignment Operator

   TSmArray & operator=(const TSmArray &other){
       
   }
   
   //[] operator overload
   
   const value_type & operator[](size_type index) const{}
   
   //[] operator overload
   
   value_type & operator[](size_type index){}
   
   // size() const function

   size_type size() const{}
   
   // empty() const function
   
   bool empty() const{}
   
   // begin() function
   
   iterator begin(){}
   
   // end() function
   
   iterator end(){}
   
   // begin() const function
   
   const_iterator begin() const{}
   
   // end() const function
   
   const_iterator end() const{}
   
   // resize() function
   
   void resize(const size_type size){}
   
   iterator insert(TSmArray<ValueType>::iterator i, ValueType v){}
   
   iterator remove(iterator i){}
   
   void swap(TSmArray &other){}

private:
   size_type _size;
   value_type *_data;
   iterator _iTer;
   const_iterator _cIter;
};

#endif
