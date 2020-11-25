#include<iostream>
#include "Date.cpp"
#include<string>
using namespace std;

bool valid_date(int d, int m, int y) 
{ 
    // If year, month and day  
    // are not in given range 
    if (y > 9999 ||  y < 1000)  //if year is greater than 9999 or less than 1000 
    return false; 				//date is not valid return false
    if (m < 1 || m > 12)        //if month is less than 1 or greater than 12 
    return false;               //date is not valid
    if (d < 1 || d > 31)        //if day is less thann 1 and more than 31
    return false;               //invalid date return false
  
    
    if (m == 2) //handle february for leap year
    { 
        if ((((y % 4 == 0)&& (y % 100 != 0)) ||(y % 400 == 0))) 
        return (d <= 29); //if leap year than days can be 29
        else
        return (d <= 28); //else days cannot be more than 28
    } 
  
    // Months of April, June,Sept and Nov cannot have number of days more than 
    // or equal to 31. 
    if (m == 4 || m == 6 || 
        m == 9 || m == 11) 
        return (d <= 30); 
  
    return true; 
} 
	
int main()
{       int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };  //array which defines all number of days in each month respectively
		
		string name; // variable to  take name
	    int bmonth = 0;  //takes birthmonth
		int bday = 0;    //takes birth date
		int byear = 0;   //takes birth year
		int cmonth = 0;  //takes current month
		int cday = 0;   //take scurrent date
		int cyear = 0;  //current year 
		int agemonth = 0;  //calc age month
		int ageday = 0; //calc age date
		int ageyear = 0; //calc age year
		
	    
	    
	    
		//Date date1,date2;  // objects of class date
		
	    cout<<"Enter Name :";  
		getline(cin, name);
		   										// gets name of user
		cout<<"enter birthdate in format dd mm yy: ";		//asks for birthdate
		cin>>bday>>bmonth>>byear;                       	//takes birthdate from user 
		Date bdate(bday,bmonth,byear);					//stores user values in the object
		if(valid_date(bday,bmonth,byear) == false)
        {
        	cout<<"invalid date for birthdate";
        	exit(0);
		}
	
		cout<<"enter present date in format dd mm yy: ";	//asks for current date
		cin>>cday>>cmonth>>cyear;							//takes current date from user
        Date cdate(cday,cmonth,cyear);                    //stores user values in the object
        if(valid_date(cday,cmonth,cyear) == false)
        {
        	cout<<"invalid date for current date";
        	exit(0);
		}
	    
	    
		//if birthday is greate than current birthmonth then do not count this month and add 30 to the date so as to subtract the date and 
    	// get the remaining days 
        if(bday > cday)  
	    { 
	    	cday = cday + month[bmonth -1];
	    	cmonth = cmonth-1;
		}
		// if birthmonth exceeds currentmonth, then do not count this year and add 12 to the month so 
        // that we can subtract and find out the difference
        
		if(bmonth > cmonth)
		{
			cyear = cyear -1;
			cmonth = cmonth + 12;
		}
		
		
		//if current date is greater than birthdate
		if(cdate > bdate) // using operators from date class
		{
		
			//calculate age i.e calc day, month, year 
			ageday = cday - bday;
			agemonth = cmonth - bmonth;
			ageyear = cyear - byear;
			//outputs data
			cout<<"Name : "<<name<<endl;
			cout << "Birthday: " << string(bdate) << " which was " << ageyear << " years, "
        	<< agemonth << " months and " << ageday << " days ago.";
			cout << "(End date considered: " << cday << "/" << cmonth << "/" << cyear << ")"<<endl;	
		
	        //checks for leap year
			if (bdate.isLeapYear() == true)  //checks if birthyear is leap year
			cout<<name<<" : was born in a leap year";
			else
			cout<<name<<" : was not born in a leap year";
	   }
	   //if birth year is greater than current year the age cannot be calculated
	   else if(bdate > cdate)
		{
			cout<<"cannot calculate age... birth year  is greater than current year";
			exit(0);
		}
		
		 
}

