//  birthday.h
//  HW1
//  Author: Rijo Simon
//  Date: 9/6/13.
//  Copyright (c) 2013 Rijo Simon. All rights reserved.

#ifndef BIRTHDAY_H
#define BIRTHDAY_H

#include <iostream>
#include <string>
#include <sstream>

class Birthday
{
    friend std::ostream & operator<<(std::ostream &, const Birthday);
private:
    
   std::string _name;
    int _date;
    int _month;
    
public:
    
    Birthday();
    
    Birthday(std::string n, int date, int month);
    
    std::string getName() const;
    
    int getMonth() const;
    
    int getDay() const;
    
    void setName(std::string n);
    
    void setMonth(int month);
    
    void setDay(int date);
    
    std::string toString() const;

   bool operator==(const Birthday & a) const;
   bool operator!=(const Birthday & a) const;
    
};

#endif //#ifndef BIRTHDAY_H
