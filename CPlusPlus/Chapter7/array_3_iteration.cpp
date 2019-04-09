#include<iostream>
#include<array>
using namespace std;

const int arraySize = 3;
int main()
{
    array<int,arraySize> arrayOne = {1,2,3};
    cout<<"# 1 #"<<endl;
    for(int item : arrayOne)
        cout<< item << " ";
    
    cout<<"\n# 2 #"<<endl;
    for(int &itemRef : arrayOne)
        itemRef *= 2;
    

    for(int item:arrayOne)
        cout<<item<<" ";

    cout << endl;

    return 0;
}