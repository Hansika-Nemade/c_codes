/**
* @file: code03.cpp
* @brief: 
* @author: Hansika Nemade(hansikanemade2121@gmail.com)
* @date: 19 Nov 2023 (sunday)
*/


// Headers
#include<iostream>
#include<vector>

#define  MaxMarks       300
#define  NoOfStudents   10

//class declaration
class StudentDetails
{
 private:
    // private data members
    const char* cStudentName;
    char        cGrade;
    float       fSubject1;
    float       fSubject2;
    float       fSubject3;
    float       fTotalMarks;
    //const char  cMaxMarks;
    unsigned char    cRollNo;
    float       fPercentage;

    // private member functions
    void SetTotalMarks(void)
    {
        float fTemp;
        fTemp = fSubject1 + fSubject2 + fSubject3;

        if(fTemp <= MaxMarks)
          fTotalMarks = fTemp;
        else
          std::cout<< "\nError: Total Marks is greater than Maximum Marks" <<std::endl;

        return;
    } 

    void SetPercentage(void)
    {
        fPercentage  = (fTotalMarks / MaxMarks) * 100;

        return;
    }
    
    void SetGrade(void)
    {
        if(fTotalMarks >= 90)
            cGrade = 'A';
        else if(fTotalMarks >= 80 )
            cGrade = 'B';
        else if(fTotalMarks >= 70)
            cGrade = 'C';
        else if(fTotalMarks >= 60)
            cGrade = 'D';
        else
            cGrade = 'F';
        
    }

 public:
    // public members functions

    // Default constructor
    StudentDetails() : cStudentName(""), cGrade(' '), fSubject1(0.0), fSubject2(0.0), fSubject3(0.0), fTotalMarks(0.0), 
                       fPercentage(0.0), /*cMaxMarks(MaxMarks),*/ cRollNo(0)
    {

    }

    // parameterized constructor
    StudentDetails(const char* cInitName, float fInitSub1, float fInitSub2, float fInitSub3, short sInitRoll) : /*cMaxMarks(MaxMarks),*/
                   cStudentName(cInitName), cRollNo(sInitRoll)
    {
        if(fSubject1 > 100 || fSubject2 > 100 || fSubject3 > 100)
        {
            std::cout<< "\n Marks can't be greater than 100" <<std::endl;
        }
        else
        {
            fSubject1 = fInitSub1; 
            fSubject2 = fInitSub2;
            fSubject3 = fInitSub3;
        }

        SetTotalMarks();
        SetPercentage();
        SetGrade();
    }

    //  Setter
    void SetName(const char* cName)
    {
        cStudentName = cName;
        return;
    }

    bool SetSubject1(float fMarks)
    {
        if(fMarks > 100)
        {
           std::cout<< "\n Marks can't be greater than 100" <<std::endl;
           return false;
        }

        fSubject1 = fMarks;
        return true;
    }

    bool SetSubject2(float fMarks)
    {
        if(fMarks > 100)
        {
           std::cout<< "\n Marks can't be greater than 100" <<std::endl;
           return false;
        }

        fSubject2 = fMarks;
        return true;
    }

    bool SetSubject3(float fMarks)
    {
        if(fMarks > 100)
        {
           std::cout<< "\n Marks can't be greater than 100" <<std::endl;
           return false;
        }

        fSubject3 = fMarks;
        return true;
    }

    void SetRollNo(short sRoll)
    {
        cRollNo = sRoll;
        return;
    }

    // Getter
    const char* GetName(void)
    {
        return cStudentName;
    }

    float GetSubject1(void)
    {
        return fSubject1;
    }

    float GetSubject2(void)
    {
        return fSubject2;
    }

    float GetSubject3(void)
    {
        return fSubject3;
    }

    float GetTotalMarks(void)
    {
        return fTotalMarks;
    }

    /*float GetMaxMarks(void)
    {
        return cMaxMarks;
    }*/

    short GetRollNo(void)
    {
        return cRollNo;
    }

    float GetPercentage(void)
    {
        return fPercentage;
    }

    void DisplayDetails(void)
    {
        //std::cout<< "\n\tStudent Details" <<std::endl;
        std::cout<< "\nStudent Name : " << cStudentName <<std::endl;
        std::cout<< "Roll No. : "  << (short)cRollNo <<std::endl;
        std::cout<< "Subject1 : "  << fSubject1 <<std::endl;
        std::cout<< "Subject2 : "  << fSubject2 <<std::endl;
        std::cout<< "Subject3 : "  << fSubject3 <<std::endl;
        std::cout<< "Total Marks : " << fTotalMarks << " , Out of : " << MaxMarks <<std::endl;
        std::cout<< "Percentage : " << fPercentage << "%   Grade : " << cGrade <<std::endl;

        return;
    } 


};

class TestRecord
{
 private:
    // Private data members
    unsigned short sStudentPresent;
    const char* cTestName;
    StudentDetails sStudents[NoOfStudents];
    //std::vector<StudentDetails> sStudents;

 public:
    // public member functions

    // Default constructor
    TestRecord() : sStudentPresent(0), cTestName("")
    {

    }

    // parameterized constructor
    TestRecord(unsigned short sInitPresent, const char* cInitTest) : cTestName(cInitTest)
    {
        if(sInitPresent < 0 || sInitPresent >NoOfStudents)
        {
            std::cout<< "student count can't be greater than Total No. of Students" <<std::endl;
        }
        else
        {
            sStudentPresent = sInitPresent;
        }
    }

    // setter
    void SetStudentPresent(unsigned short sCount)
    {
        sStudentPresent = sCount;
    }

    void SetTestName(const char* cName)
    {
        cTestName = cName;
    }

    void SetStudentDetails(short sInitRoll, const char* cInitName, float fInitSub1, float fInitSub2, float fInitSub3 )
    {
        if(sInitRoll <= 0 || sInitRoll > NoOfStudents)
        {
            std::cout<< "\nInvalid Roll NO." <<std::endl;
            return;
        }
        sStudents[sInitRoll - 1].SetName(cInitName);
        sStudents[sInitRoll - 1].SetRollNo(sInitRoll);
        sStudents[sInitRoll - 1].SetSubject1(fInitSub1);
        sStudents[sInitRoll - 1].SetSubject2(fInitSub2);
        sStudents[sInitRoll - 1].SetSubject3(fInitSub3);

        return;
    }

    // Getter
    unsigned short GetStudentPresent(void)
    {
        return sStudentPresent;
    }

    const char* GetTestName(void)
    {
        return cTestName;
    }

    void DisplayDetails(void)
    {
        std::cout<< "\n\t Test Details" <<std::endl;
        std::cout<< "Test Name : " << cTestName <<std::endl;
        std::cout<< "Student count for Test : " << sStudentPresent <<std::endl;

        for(int le = 0; le < NoOfStudents; le++)
        {
            sStudents[le].DisplayDetails();
            std::cout<< "--------------------------------------------------------------------------" <<std::endl;
        }

        return;
    }
};


// Entry point of main function
int main(int argc, char** argv)
{
    TestRecord Record(7, "ABCD");

    Record.SetStudentDetails(1, "XYZ", 91, 53, 78);
    Record.SetStudentDetails(2, "Ramesh", 69, 52, 81);
    Record.SetStudentDetails(3, "Suresh", 46, 77, 63);
    Record.SetStudentDetails(4, "Sita", 80, 92, 96);
    Record.SetStudentDetails(5, "Geeta", 21, 76, 62);
    Record.SetStudentDetails(6, "Shyam", 55, 71, 44);
    Record.SetStudentDetails(7, "ABCD", 78, 66, 61);
    Record.SetStudentDetails(8, "PQR", 89, 94, 104);
    Record.SetStudentDetails(9, "XYZ", 45, 67, 83);
    Record.SetStudentDetails(10, "XYZ", 78, 74, 86);

    Record.DisplayDetails();

    exit(0);
}

