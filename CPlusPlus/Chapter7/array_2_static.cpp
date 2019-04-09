#include<iostream>
#include<array>
using namespace std;

const size_t arraySize = 3;


//static 会将状态量保持在那里，下次调用还是可以
void staticArrayInit()
{
    static array<int,arraySize> arrayOne;
    cout<<"#init_1#"<<endl;
    for(size_t i = 0;i<arrayOne.size();i++)
        cout<<"arrayOne["<<i<<"] = "<<arrayOne[i]<<" ";
    cout<<"\n#after_1#"<<endl;
    for(size_t j = 0;j<arrayOne.size();j++)
        cout<<"arrayOne["<<j<<"] = "<<(arrayOne[j]+=5)<<" ";
}

void automaticArrayInit()
{
    array<int,arraySize> arrayTwo = {1,2,3};
    cout<<"\n#init_2#"<<endl;
    for(size_t i = 0 ;i<arrayTwo.size(); i++)
        cout<<"arrayTwo["<<i<<"] = "<< arrayTwo[i] <<" ";

    cout<<"\n#after_2#"<<endl;
    for(size_t j = 0;j<arrayTwo.size();j++)
        cout<<"arrayTwo["<<j<<"] = "<<(arrayTwo[j] += 5)<<" ";
}



int main()
{
    cout<<"\nFirst time!!!"<<endl;
    staticArrayInit();
    automaticArrayInit();

    cout<<"\nSecond time!!!"<<endl;
    staticArrayInit();
    automaticArrayInit();
    return 0;
}