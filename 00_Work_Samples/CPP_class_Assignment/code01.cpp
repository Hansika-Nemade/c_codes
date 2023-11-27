/**
* @file: code01.cpp
* @brief: simple bank account class with their private data members and public member functions to access and modify them
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 16 Nov 2023 (Thusday)
*/

// Headers
#include<iostream>

#define IFSC_SIZE   12
#define NO_TYPE     0
#define SAVINGS     1
#define CURRENT     2


// class declaration
class BankAccount
{
 private:
    //   private data members
    const char*    cAccountHolder ;
    double         dBalance;
    const char*    cIFSCCode;
    const char*    cAddress;
    unsigned char  SAccountType;

 public:
    // public member function

    // Default constructor
    BankAccount()
    {
        this->cAccountHolder = "";
        this->dBalance = 0.0;
        this->cIFSCCode = "";
        this->cAddress = "";
        this->SAccountType = NO_TYPE;
    }

    // parameterize constructor 
    BankAccount(const char* cHolder, double dInit_Balance,const char* cCode, const char* cAddress, int iInit_Type)
               : cAccountHolder(cHolder), dBalance(dInit_Balance), cAddress(cAddress), SAccountType(iInit_Type), cIFSCCode(cCode)        
    {
        /*for(int le = 0; le < IFSC_SIZE; le++)
        {
            cIFSCCode[le] = code[le];
        }*/
    }

    const char* GetAccountHolder(void)
    {
        return cAccountHolder;
    }

    double GetBalance(void)
    {
        return dBalance;
    }

    const char* GetAddress(void)
    {
        return cAddress;
    }

    int GetAccountType(void)
    {
        return SAccountType;
    }

    const char* GetIFSC(void)
    {
        return cIFSCCode;
    }

    bool Deposit(double Amount)
    {
        if(Amount > 0)
        {
            dBalance = dBalance + Amount;
            std::cout<< "\nAmount " << Amount << "Rs is successfully credited" <<std::endl; 
            return true;
        }
        else
        {
            std::cout << "Invalid deposit amount." << std::endl;
            return false;
        }
    }

    bool Withdraw(double Amount)
    {
        if(Amount > 0 && Amount <= dBalance)
        {
            dBalance = dBalance - Amount;
            std::cout<< "\nAmount " << Amount << "Rs is successfully debited" <<std::endl;
            return true;
        }
        else
        {
            std::cout << "Invalid amount or insufficient balance." << std::endl;
            return false;
        }
    }

    void DisplayDetails(void)
    {
        std::cout<< "\nAccount Holder : " << cAccountHolder <<std::endl;
        std::cout<< "Address : " << cAddress <<std::endl;
        std::cout<< "Balance : " << dBalance << "Rs" << std::endl;
        std::cout<< "IFSC Code : " << cIFSCCode <<std::endl;
        
        if(SAccountType == SAVINGS)
        {
            std::cout<< "Account Type : SAVINGS" <<std::endl;
        }
        else if(SAccountType == CURRENT)
        {
            std::cout<< "Account Type : CURRENT" <<std::endl;
        }

        return;
    }


    // destructor
    ~BankAccount()
    {
        
    }

};

// Entry point of main function
int main(int argc, char** argv)
{
    BankAccount Account1("Geeta", 5000, "ABCD100005GI", "Near city Hospital", SAVINGS);

    Account1.DisplayDetails();

    Account1.Deposit(500.56);

    std::cout<< "\nBalance : " << Account1.GetBalance() << "Rs" <<std::endl;

    Account1.Withdraw(1209);
    std::cout<< "\nBalance : " << Account1.GetBalance() << "Rs" <<std::endl;

    Account1.Withdraw(9000);

    std::cout<< "current Address : " << Account1.GetAddress() << std::endl;

    Account1.DisplayDetails();

    exit(0);
}

