/**
* @file: code02.cpp
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 16 Nov 2023 (Thursday)
*/

// Headers
#include<iostream>


// class declaration
class Calculator
{
 private:
    // private data members


    // private member functions
    double Addition(double dNum1, double dNum2)
    {
        return dNum1 + dNum2;
    }

    double Subtraction(double dNum1, double dNum2)
    {
        return dNum1 - dNum2;
    }

    double Multiplication(double dNum1, double dNum2)
    {
        return dNum1 * dNum2;
    }

    double Division(double dNum1, double dNum2)
    {
        if(dNum2 != 0)
        {
            return dNum1 / dNum2;
        }

        std::cout<< "Error: Division by 0 " << std::endl;
        return 0.0;
    }

    int Reminder(int iNum1, int iNum2)
    {
        if(iNum2 != 0)
        {
            return iNum1 % iNum2;
        }

        std::cout<< "Error: Division by 0 " << std::endl;
        return 0;
    }

 public:
    // public member functions

    // Default constructor
    Calculator()
    {

    }

    
    int  Calculations(double dNum1, double dNum2, char cOperation)
    {
        switch(cOperation)
       {
            case '+':
               return Addition(dNum1, dNum2);
               //break;

            case '-':
               return Subtraction(dNum1, dNum2);
               //break;

            case '*':
               return Multiplication(dNum1, dNum2);
               //break;

            case '/':
               return Division(dNum1, dNum2);
               //break;

            case '%':
               return Reminder(dNum1, dNum2);
               //break;
            default:
               std::cout<< "Error: Invalid operation" <<std::endl;
               return 0;
       }
    }

    // Destructor
    ~Calculator()
    {

    }

};


// Entry point of main function
int main(int argc, char** argv)
{
    double dUserNum1 = 0.0, dUserNum2 = 0.0;
    char cOperation = ' ';
    double dResult = 0.0;
    Calculator cObject;

    std::cout<< "Enter operand 1: ";
    std::cin>> dUserNum1;

    std::cout<< "Enter operation" ;
    std::cin>> cOperation;

    std::cout<< "Enter operand 2: ";
    std::cin>> dUserNum2;

    dResult = cObject.Calculations(dUserNum1, dUserNum2, cOperation);
    std::cout<< "\n" << dUserNum1 << " " << cOperation << " " << dUserNum2 << " = " << dResult <<std::endl;

    exit(0);
}
