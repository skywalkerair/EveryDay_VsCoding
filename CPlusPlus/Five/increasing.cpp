#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    double input = 1000.0;
    int year = 1;
    double rate = 0.05;

    double result = 0;
    for(year;year<= 10;year++){
         result = input*pow(1+rate,year);
         cout<<"result:"<<result<<endl;
    }

    return 0;
}