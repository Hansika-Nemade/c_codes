
// Headers
#include	<iostream>
#include	"date.hpp"

// object creation
Date date_1(10, MONTH::FEBRUARY, 2023);

//     ENTRY POINT OF MAIN FUNCTION
int main(int argc, char** argv, char** envp)
{
   date_1.Print();
   std::cout<< std::endl;

   date_1.CheckValidity();

   date_1.SetDateDay(31);
   
   date_1.Print();
   std::cout<< std::endl;

   date_1.CheckValidity();
   std::cout<< std::endl;

   date_1.SetFormat(FORMAT::MMMM_DD_YYYY);

   date_1.Print();
   std::cout<< std::endl;

   date_1.SetDateDay(1);
   
   date_1.Print();
   std::cout<< std::endl;

   exit(EXIT_SUCCESS);
}
