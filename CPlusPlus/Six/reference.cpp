#include<iostream>
using namespace std;

int squareByValue(int);
void squareByReference(int &);

int main()
{
    int x = 2;
    int z = 4;

    cout<<"before x:"<<x<<endl;
    cout<<"aquareByValue:"<<squareByValue(x)<<endl;
    cout<<"after x:"<<x<<endl;
    cout<<"before z:"<<z<<endl;
    squareByReference(z);
    cout<<"after z:"<<z<<endl;

}

int squareByValue(int number){
    return number *= number;
}

void squareByReference(int &number){
    number *= number;
}