#include<iostream>
#include<iomanip>
using namespace std;

unsigned long factorial(unsigned int);

int main()
{
    for(unsigned int i = 0;i<=10;i++)
        cout<<setw(2)<<i<<"!="<<factorial(i)<<endl;
}

unsigned long factorial(unsigned int number)
{
    unsigned int result = 1;

    for(unsigned int i = number;i>=1;i--)
        result *= 1;
    return result;
}