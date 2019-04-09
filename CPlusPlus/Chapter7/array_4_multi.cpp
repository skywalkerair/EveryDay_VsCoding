#include<iostream>
#include<array>
using namespace std;

const size_t rows = 2;
const size_t columns = 3;
void printArray(const array<array<int,columns>,rows> &);
void printArrayAuto(const array<array<int,columns>,rows> & a);
int main()
{
    array<array<int,columns>,rows> array1 = {1,2,3,4,5,6};
    array<array<int,columns>,rows> array2 = {1,2,3,4,5};

    cout<< "## 1 ##"<<endl;
    printArray(array1);
    printArrayAuto(array1);

    cout<<"## 2 ##"<<endl;
    printArray(array2);
    printArrayAuto(array2);

    return 0;
}

void printArray(const array<array<int,columns>,rows> & a)
{
    //array.size()表示的是行数，array[row].size()表示的是列数
    //大循环先循环行数，再循环列数
    for(size_t row = 0;row<a.size();row++)
    {
        for(size_t columns = 0;columns<a[row].size();columns++)
            cout<<a[row][columns]<<" ";
        cout << endl;
    }    

}
void printArrayAuto(const array<array<int,columns>,rows> & a )
{
    for(auto const & row:a)
    {
        for(auto const & element : row)
            cout<<element <<' ';
        cout<<endl;
    }

}

