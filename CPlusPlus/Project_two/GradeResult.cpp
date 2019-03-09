#include<iostream>

using namespace std;

int main()
{
    unsigned int successed = 0;
    unsigned int failed = 0;
    unsigned int studentCounter = 1;

    while(studentCounter <= 10)
    {
        cout<< "Enter result(1 = pass,2 = fail):";
        int result;
        cin>> result;

        if(result == 1)
        {
            successed += 1;
        }
        else{
            failed += 1;
        }

        studentCounter += 1;
    }
    cout<< "Passed:"<<successed <<"\n Failed:"<<failed <<endl;
    if(successed > 8)
    {
        cout<< "Bonus to instructor!"<<endl;
    }
    return 0;
}