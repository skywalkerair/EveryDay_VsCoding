#include<iostream>
#include<array>
#include<iomanip>
using namespace std;
int main()
{
    array<int,5> n;
    for(size_t i = 0;i<n.size();i++)
        n[i] = 0;

    cout << "Element"<<setw(13)<<"Value"<<endl;

    for(size_t j = 0;j<n.size();j++)
        cout<< setw(7)<<j<<setw(13)<<n[j]<<endl;
    

    array<int,5> m= {};
    for(size_t array_j = 0;array_j < m.size();array_j++)
        cout<< m[array_j]<<endl;

    array<int,5> l = {12,3,11,24,11};
    for(size_t array_i = 0;array_i < l.size();array_i++)
        cout<< l[array_i]<<endl;
    return 0;
}
