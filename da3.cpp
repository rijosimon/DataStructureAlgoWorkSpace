// da3.cpp (skeleton)
// Chris Hartman
// 2/12/2010
// 
// based on material by
// Glenn G. Chappell
// 25 Sep 2009
// 
// For CS 311 Spring 2010
// Source file for Assignment 3

#include "da3.h"


int collatz(int n)
{
    int steps = 1;
    if(n == 1)
    {
    	steps = 0;
    }
    else if(n%2 == 0)
    {	
    	steps+=collatz(n/2);
    }
    else if(n%2 != 0)
    {
    	steps+=collatz((3*n)+1);
    }
    return steps;
}
