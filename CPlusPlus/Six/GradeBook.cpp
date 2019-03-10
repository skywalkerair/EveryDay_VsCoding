#include<iostream>
#include"GradeBook.h"
#include<iomanip>

using namespace std;

GradeBook::GradeBook(string name)
:aCount(0),
 bCount(0),
 cCount(0),
 dCount(0),
 fCount(0)
{
    setCourseName(name);
}

void GradeBook::setCourseName(string name){
    if(name.size() <=25)
        courseName = name;
    else{
        courseName = name.substr(0,25);
        //select first 25 characters
        cerr<<"Name \""<<name <<"\" exceeds maximun length(25).\n"
        <<"Limiting courseName to first 25 characters/\n"<<endl;
    }
}

string GradeBook::getCourseName() const
{
    return courseName;
}

void GradeBook::displayMessage() const
{
    cout<< "Welcome to the grade book for \n"<< getCourseName() <<"!\n"
    <<endl;
}

void GradeBook::determineClassAverage() const
{   
    int total = 0;
    unsigned int gradeCounter = 0;//1-10 use unsigned int 
    
    cout<<"Enter grade or -1 to quit:";
    int grade = 0;
    cin >> grade;

    while(grade != -1)
    {
        total  = total + grade;
        gradeCounter += 1;

        cout<<"Enter grade or -1 to quit:";
        cin >> grade;
    }

    if(gradeCounter != 0)
    {
        double average = static_cast<double>(total)/gradeCounter;

        cout <<"\n Total of all "<<gradeCounter<<" grades entered is "
        <<total<<endl;
        cout<< setprecision(2)<<fixed;
        cout<<"Class average is "<<average<<endl;
    }
    else{
        cout<< "No grades were  entered"<<endl;
    }
}
void GradeBook::inputGrades_five()
{
    int grade;
    cout<< "Enter the letter grades."<<endl
    <<"Enter the EOF character to end input."<<endl;

    while((grade = cin.get()) != EOF)
    {
        cout<<"int Grade:"<<grade<<endl;
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
            case 'F':
            case 'f':
                ++fCount;
                break;
            case '\n':
            case '\t':
            case ' ':
                break;
            default:
                cout<< "Incorrect letter grade entered."
                <<"Enter a new grade."<<endl;
                break;
        }
    }
}

void GradeBook::displayGradeReport_five() const
{
    cout<< "\n\nNumber of students who received each letter grade:"
    <<"\nA:"<<aCount
    <<"\nB:"<<bCount
    <<"\nC:"<<cCount
    <<"\nD:"<<dCount
    <<"\nF:"<<fCount
    <<endl;
}


void GradeBook::inputGrades_six()
{
    int grade1;
    int grade2;
    int grade3;

    cout<<"Enter three integer grades:";
    cin>>grade1>>grade2>>grade3;

    maximumGrade = maximun(grade1,grade2,grade3); 
}


int GradeBook::maximun(int x,int y,int z) const
{
    int maximumValue = x;//assume x is the max

    if(y>maximumValue)
        maximumValue = y;
    if(z>maximumValue)
        maximumValue = z;

    return maximumValue;
}


void GradeBook::displayGradeReport_six() const
{
    cout<<"Maximum of grades entered:"<<maximumGrade<<endl;
}