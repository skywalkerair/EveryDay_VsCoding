#include<iostream>
#include<iomanip>
#include<cstdlib>
using namespace std;

int main()
{
    unsigned int seed = 0;
    cout<< "Enter seed: ";
    cin >> seed;
    srand(seed);

    for(unsigned int i = 0;i<=10;i++)
    {
        cout<<setw(10)<<(1+rand()%6);
        if(i %5 == 0)
            cout<<endl;
    }
}