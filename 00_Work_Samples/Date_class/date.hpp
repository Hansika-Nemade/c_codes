
#pragma once

#include<iostream>

#include	"day.hpp"
#include	"month.hpp"
#include	"year.hpp"
 	
enum  class FORMAT
{
   D_MM = 1,
   DD_MM,
   D_MM_YY,
   DD_MM_YY,
   D_MM_YYYY,
   DD_MM_YYYY,
   MM_DD_YY,
   MM_DD_YYYY,
   MMMM_DD_YYYY
};


//  class type definition
class  Date
{
 private:
   // data members
   Day		m_day;
   Month	m_month;
   Year	    m_year;
   FORMAT	m_format;

   //  member function
   bool    is_Date_Valid()
   {
        //	 CASE 1: Day between 1 to 28 and year between 1970 to 3000
        if( m_day.is_Valid() && m_year.is_Valid() )
		{
			return(true);
		}

        // Case 2:  Check For Month is Feb   Check For Year is Leap      Check For Day is 29  
		else if(m_month.is_February()  &&   m_year.is_LeapYear()	&&	m_day.getDay() == 29)	
		{
			return(true);
		}

        // CASE 3: Check Month for 31 Days and Check Day for extra days
		else if( m_month.is_31Days()  &&  (GetDateDay() >= 29 && GetDateDay() <= 31) )
		{
			return(true);
		}

        //  CASE 4: Check Month for 30 Days and Check Day for extra days
		else if( !(m_month.is_31Days())     && 					   //	Not 31 Days Months
				 !(m_month.is_February())   && 				       //	Not February
				 (GetDateDay() >= 29 && GetDateDay() <= 30) )	   //	Days from 29 top 30
		{
			return(true);
		}

        return(false);
   }

 public:
    //  member functions
    //  default constructor
    Date(): m_day(Day()), m_month(Month()), m_year(Year()), m_format(FORMAT::DD_MM_YYYY)
    {
       
    }

    // parameterized constructor
    Date( unsigned short init_day = EPOCH_DAY, MONTH init_month = EPOCH_MONTH, unsigned long init_year = EPOCH_YEAR) : 
	m_day(Day(init_day)), m_month(Month(init_month)), m_year(Year(init_year))
	{

	}

    Date( MONTH init_month = EPOCH_MONTH) : m_day(Day()),	m_month(Month(init_month)),m_year(Year())
	{

	}

    Date( unsigned long init_year = EPOCH_YEAR ) : m_day(Day()), m_month(Month()), m_year(Year(init_year))
	{

	}

    //	Setter 
	void SetDateDay(unsigned short new_day) 
	{ 
	   this->m_day.setDay(new_day); 
	}

	void SetDateMonth(MONTH new_month) 
	{ 
	   this->m_month.SetMonth(new_month); 
	}

	void  SetDateYear(unsigned long new_year)
	{
	    this->m_year.SetYear(new_year);
	}

	void SetDate( unsigned short new_day, MONTH new_month, unsigned long new_year )
	{
		SetDateDay(new_day);
		SetDateMonth(new_month);
		SetDateYear(new_year);
	}

	void SetFormat(FORMAT new_format)
	{
		this->m_format = new_format;
	}

	//	Getter 
	unsigned short GetDateDay() 
    { 
       return(this->m_day.getDay()); 
    }

	MONTH GetDateMonth() 
    { 
       return(this->m_month.GetMonth()); 
    }

	unsigned long GetDateYear() 
    { 
       return(this->m_year.GetYear()); 
    }

    void CheckValidity()
	{
	   if( is_Date_Valid() )
       {
		  std::cout<< "The Date :" << GetDateDay() << "/" << this->m_month.ToString() << "/" << GetDateYear() << " is a valid date." 
          <<std::endl;
       }
	   else
       {
		  std::cout<< "The Date :" << GetDateDay() << "/" << this->m_month.ToString() << "/" << GetDateYear() << " is NOT a valid date." 
          <<std::endl;
       }
	}

    void	Print()
	{
	  switch(m_format)
	  {
		case FORMAT::D_MM_YYYY:
			std::cout<< "Date: " << m_day.doubleDigit() << "/" << this->m_month.ToString() << "/" << GetDateYear() <<std::endl;
			break;

		case FORMAT::DD_MM_YYYY:
			std::cout<< "Date: " << m_day.doubleDigit() << "/" << this->m_month.ToString() << "/" << GetDateYear() <<std::endl;
			break;

		case FORMAT::MMMM_DD_YYYY:
			std::cout<< "Date: " << this->m_month.ToStringName() << " " << m_day.doubleDigit() << ", " << GetDateYear() <<std::endl;
			break;
	   }
	}

};