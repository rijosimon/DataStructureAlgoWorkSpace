//
//  birthday.cpp
//  HW1
//
//  Created by Rijo Simon on 2/8/13.
//  Copyright (c) 2013 Rijo Simon. All rights reserved.
//

#include "birthday.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>

Birthday::Birthday()
{
    _name = "";
    _month = 1;
    _date = 1;
}

Birthday::Birthday(std::string nameRec, int monthRec, int dateRec)
{
    _name = nameRec;
    _month = monthRec;
    _date = dateRec;
}

std::string Birthday::getName() const
{
    return _name;
}

int Birthday::getMonth() const
{
    return _month;
}

int Birthday::getDay() const
{
    return _date;
}

void Birthday::setName(std::string n)
{
    _name=n;
}

void Birthday::setMonth(int month)
{
    _month = month;
}

void Birthday::setDay(int date)
{
    _date=date;
}

std::string Birthday::toString() const
{
    //std::cout<<_name<<" "<<_date<<" "<<_month<<"\n";
    std::string monthsName[]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov" ,"Dec"};
    std::string dateValue[]={"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31"};
    std::string returnString = _name + " ("+monthsName[_month-1]+" "+dateValue[_date-1]+")";
    //std::cout<<returnString;
    return returnString;
}

bool Birthday::operator==(const Birthday & a) const
{
    if(this->_name == a._name && this->_month == a._month && this->_date == a._date)
    {
        return true;
    }
    
    return false;
}

bool Birthday::operator!=(const Birthday & a) const
{
    if(this->_name != a._name || this->_month != a._month || this->_date != a._date)
    {
        return true;
    }
    
    return false;
}

std::ostream & operator<<(std::ostream & os , const Birthday c)
{
	return os<<c.toString;
}



