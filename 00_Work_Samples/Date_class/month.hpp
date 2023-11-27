
#pragma	once

enum class MONTH
{
   JANUARY = 1,
   FEBRUARY,
   MARCH,
   APRIL,
   MAY,
   JUNE,
   JULY,
   AUGUST,
   SEPTEMBER,
   OCTOBER,
   NOVEMBER,
   DECEMBER
};

#define	  EPOCH_MONTH	MONTH::JANUARY


//   class type definition
class  Month
{
 private: 
    //   Data members
    MONTH m_month;

 public:
    //   Member functions
    //   default constructor
    Month(): m_month(EPOCH_MONTH)
	{

	}

    //  Parameterized constructor
	Month(MONTH init_month): m_month(init_month)
	{

	}

    //  setter
    void SetMonth(MONTH new_month) 
    { 
       this->m_month = new_month; 
    }

    //  getter
    MONTH GetMonth() 
    { 
       return(this->m_month); 
    }

	bool  is_February() 
	{
		if( MONTH::FEBRUARY == m_month )
			return(true);

		return(false);
	}

    bool	is_31Days()
	{
		if(	MONTH::JANUARY	==	m_month	|| MONTH::MARCH	==	m_month	||
			MONTH::MAY	==	m_month	    || MONTH::JULY	==	m_month	||
			MONTH::AUGUST	==	m_month	|| MONTH::OCTOBER	==	m_month	|| MONTH::DECEMBER	==	m_month	)
        {
			return(true);
        }

		return(false);
	}

    const char* ToString()
	{
		switch(m_month)
		{
		  case MONTH::JANUARY:
			return("01");
		
		  case MONTH::FEBRUARY:
			return("02");

		  case MONTH::MARCH:
			return("03");

		  case MONTH::APRIL:
			return("04");

		  case MONTH::MAY:
			return("05");

		  case MONTH::JUNE:
			return("06");

		  case MONTH::JULY:
			return("07");

		  case MONTH::AUGUST:
			return("08");

		  case MONTH::SEPTEMBER:
			return("09");

		  case MONTH::OCTOBER:
			return("10");

		  case MONTH::NOVEMBER:
			return("11");

		  case MONTH::DECEMBER:
			return("12");
		
		  default:
			return("0");
		}
	}

    const char* ToStringName()
	{
		switch(m_month)
		{
		  case MONTH::JANUARY:
			return("January");
		
		  case MONTH::FEBRUARY:
			return("February");

		  case MONTH::MARCH:
			return("March");

		  case MONTH::APRIL:
			return("April");

		  case MONTH::MAY:
			return("May");

		  case MONTH::JUNE:
			return("June");

		  case MONTH::JULY:
			return("July");

		  case MONTH::AUGUST:
			return("August");

		  case MONTH::SEPTEMBER:
			return("September");

		  case MONTH::OCTOBER:
			return("October");

		  case MONTH::NOVEMBER:
			return("November");

		  case MONTH::DECEMBER:
			return("December");
		
		  default:
			return("None");
		}
	}

    // destructor
    ~Month()
    {
        
    }

};