#include<iostream>
#include<string>
#include <iomanip>
#include "Date.h"
using namespace std;

Date::Date()    // date class constructor
{
	this -> d = 1;
	this -> m = 1;
	this -> y = 1000;
}
Date::Date(unsigned int day, unsigned int month, unsigned int year)  //constructor in which we store the date
{  
	this->d = day;
	this->m = month;
	this->y = year;
	
}
 bool Date::isLeapYear() const   //constructor to check whether year is a leap year or not
{
	
	if((((y % 4 == 0)&& (y % 100 != 0)) ||(y % 400 == 0)))
    {
		return true;
	}	
    else
    {
    	return false;
	}
    	
}

 bool Date::operator<(const Date& other) const   //operator to check if date 1 is less than date2
{
	if(this->y<other.y)        //if year1 is less than year2 return date1 is less than date2
		return true;
		
	else if(this->y==other.y)    //if both years are equal check months 
	{							//if month 1 is less than month2 return date1 less than date2 
		if(this->m<other.m)
			return true;
		else if(this->m==other.m)
		{
			if(this->d<other.d)   //if day1 is less than  day2 return date1 less than  day2
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else 
		return false;
}
bool Date::operator>(const Date& other) const   //operator to check if date1 is greater than date2
{
	if(this->y>other.y)           //if year1 is greater than year2 return date1 is greater than date2
		return true;
		
	else if(this->y==other.y)     //if both years are equal check months 
	{	                          
		if(this->m>other.m)       //if month 1 is greater than month2 return date1 greater than date2 
			return true;
		else if(this->m==other.m)
		{
			if(this->d>other.d)
				return true;     //if day1 is greater than  day2 return date1 greater than  day2
			else
				return false;
		}
		else
			return false;
	}
	else 
		return false;
}

Date::operator string() const     //returns date like july 16 , 1857
{   static string months[13] = {" ","January", "February",
        "March", "April", "May", "June", "July", "August",
        "September", "October", "November", "December" };
	string s= "BirthDate : " + months[m] + " " + to_string(this->d)+ "," + to_string(this->y);
	return s;
}
ostream& operator<<(ostream& o, const Date& d)   // returns date in like 16/07/1857
{
    o << setw(2)<<setfill('0') << d.d << "/"<< setw(2)<< setfill('0')<< d.m << "/" <<d.d;
    return o;
}


