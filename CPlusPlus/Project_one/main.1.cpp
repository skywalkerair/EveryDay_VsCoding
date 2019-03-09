#include<iostream>
#include"GradeBook.h"

using namespace std;

int main()
{    
    GradeBook gradebook1("Instroduction to C++ Programming");
    //GradeBook gradebook2("Data Structures in C++");

    gradebook1.displayMessage();
    gradebook1.determineClassAverage();
    return 0;
}