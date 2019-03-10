#include<array>
#include"GradeBook.h"
using namespace std;

int main()
{
    const array<int,GradeBook::students> grades = 
    {87,88,94,87,85,96,60,78,91,76};
    string courseName = "Welcome to the real world!";

    GradeBook myGradebook(courseName,grades);

    myGradebook.displayMessage();
    myGradebook.processGrades();
}