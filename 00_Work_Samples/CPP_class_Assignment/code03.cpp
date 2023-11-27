/**
* @file: code03.cpp
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 16 Nov 2023 (Thursday)
*/

// Headers
#include<iostream>


// class declaration
class EmployeeDetails
{
 private:
   // private data members
   const char* cEmployeeName;
   const char* cJobTitle;
   float fSalary;
   float fPerformance;

 public:
   // public member functions

   // Default constructor
   EmployeeDetails() : cEmployeeName(" "), cJobTitle(" "), fSalary(0.0), fPerformance(0.0)
   {

   }

   // parameterized constructor
   EmployeeDetails(const char* cInitName, const char* cInitTitle, float fInitSalary, float fInitPerformance) 
                  : cEmployeeName(cInitName), cJobTitle(cInitTitle), fSalary(fInitSalary), fPerformance(fInitPerformance)
   {

   }

   // Getter
   const char* GetEmployeeName(void)
   {
      return cEmployeeName;
   }

   const char* GetJobTitle(void)
   {
      return cJobTitle;
   }

   float GetSalary(void)
   {
      return fSalary;
   }

   float GetPerformance(void)
   {
      return fPerformance;
   }

   // Setter
   void SetEmployeeName(const char* cName)
   {
      this->cEmployeeName = cName;
   }

   void SetJobTitle(const char* cTitle)
   {
      this->cJobTitle = cTitle;
   }

   void SetSalary(float fSetSalary)
   {
      this->fSalary = fSetSalary;
   }

   void SetPerformance(float fSetPerformance)
   {
      this->fPerformance = fSetPerformance;
   }

   void DisplayDetails(void)
   {
      std::cout<< "\n\t Employee Details" <<std::endl;
      std::cout<< "Employee Name : " << cEmployeeName <<std::endl;
      std::cout<< "Job Title : " << cJobTitle <<std::endl;
      std::cout<< "Salary : "  << fSalary <<std::endl;
      std::cout<< "Employee Performance : " << fPerformance <<std::endl;

      return;
   }

   ~EmployeeDetails()
   {

   }

   
};


// Entry point of main function
int main(int argc, char** argv)
{
   EmployeeDetails Employee1;

   Employee1.DisplayDetails();

   Employee1.SetEmployeeName("ABCD");
   Employee1.SetJobTitle("Software Developer");
   Employee1.SetSalary(50000.00);
   Employee1.SetPerformance(9.98);

   std::cout<< "\n\t Employee Details" <<std::endl;
   std::cout<< "Employee Name : " << Employee1.GetEmployeeName() <<std::endl;
   std::cout<< "Job Title : " << Employee1.GetJobTitle() <<std::endl;
   std::cout<< "Salary : "  << Employee1.GetSalary() <<std::endl;
   std::cout<< "Employee Performance : " << Employee1.GetPerformance() <<std::endl;

   exit(0);
}

