
#pragma once

#define EPOCH_DAY     1

// class type definition
class  Day
{
 private:
    //    Data Members
    unsigned short  m_day;

 public:
    //    Member Functions
    //   Default constructor
    Day(): m_day(EPOCH_DAY)
    {

    }

    //    parameterized constructor
    Day(unsigned short init_day): m_day(init_day)
    {

    }
    
    //  setter
    void  setDay(unsigned short new_day)
    {
        this->m_day = new_day;
    }

    //   getter
    unsigned short  getDay()
    {
        return(this->m_day);
    }

    bool is_Valid()
	{
		if( m_day >= 1 && m_day <= 28 )
        {
			return(true);
        }
		return(false);
	}

    const char* doubleDigit()
    {
        switch(m_day)
		{
		  case 1:
			return("01");
		  case 2:
			return("02");
		  case 3:
			return("03");
		  case 4:
			return("04");
		  case 5:
			return("05");
		  case 6:
			return("06");
		  case 7:
			return("07");
		  case 8:
			return("08");
		  case 9:
			return("09");
          case 10:
			return("10");

          case 11:
			return("11");
		  case 12:
			return("12");
		  case 13:
			return("13");
		  case 14:
			return("14");
		  case 15:
			return("15");
		  case 16:
			return("16");
		  case 17:
			return("17");
		  case 18:
			return("18");
		  case 19:
			return("19");
		  case 20:
			return("20");

          case 21:
			return("21");
		  case 22:
			return("22");
		  case 23:
			return("23");
		  case 24:
			return("24");
		  case 25:
			return("25");
		  case 26:
			return("26");
		  case 27:
			return("27");
		  case 28:
			return("28");
		  case 29:
			return("29");
		  case 30:
			return("30");
		  case 31:
			return("31");

		  default:
			return("0");
		}

    }

    //   destructor
    ~Day()
    {

    }

};