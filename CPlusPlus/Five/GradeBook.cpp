#include<iostream>
#include<iomanip>
#include"GradeBook.h"
using namespace std;

GradeBook::GradeBook(string classname)
:aCount(0);
 bCount(0);
 cCount(0);
 dCount(0);
 eCount(0);
{
    setCourseName(classname);
}

void GradeBook::setCourseName(string name)
{
    if(name.size()<=25)
        courseName = name;
    else
    {
        courseName = name.substr(0,25);
        cerr << "Name \""<<name<<"\" exceed maximum length(25).\n"
        <<"Limiting courseName to first 25 characters.\n"<<endl;
    }
}
string GradeBook::getCourseName() const
{
    return courseName;
}
void GradeBook::displayMessage() const
{
    cout<< "Welcome to the grade book for\n"<<getCourseName()
    <<"!"<<endl;
}

void GradeBook::determineClassAverage() const
{
    int total = 0;
    unsigned int gradeCounter = 1;

    //设置一个停止键
    cout<< "Enter grade or -1 to quit:";
    int grade  = 0;
    cin >> grade;

    while(grade != -1)
    {
        total = total + grade;
        gradeCounter += 1;
        cout<<"Enter grade or -1 to quit:";
        cin >> grade;
    }
    if(gradeCounter != 0)
    {
        double average = static_cast<double>(total)/gradeCounter;

        cout<< "\nTotal of all"<<gradeCounter<<"grades entered is "
        <<total<<endl;

        cout<< setprecision(2)<<fixed;
        cout<< "Class average is "<<average<<endl;   
    }
    else
    {
        cout<<"No grades were entered!"<<endl;
    } 
}
void GradeBook::inputGrades()
{
    int grade;
    cout<<"Enter the letter grades."<<endl
    <<"Enter the EOF character to end input."<<endl;

    while((grade = cin.get())!=EOF)
    {
        switch(grade)
        {
            case 'A':
            case 'a':
                ++aCount;
                break;
            case 'B':
            case 'b':
                ++bCount;
                break;
            case 'C':
            case 'c':
                ++cCount;
                break;
            case 'D':
            case 'd':
                ++dCount;
                break;
            case 'e':
            case 'E':
                ++eCount;
                break;

            case '\n'://ignore newlines,
            case '\t'://tabs,
            case ' '://and spaces in lines
                break;//exit switch

            default:
                cout<<"Incorrect letter grade entered."
                <<"Enter a new grade."<<endl;
                break;
        }
    }

}



