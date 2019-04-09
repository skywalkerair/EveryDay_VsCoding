#include<iostream>
#include<array>
using namespace std;

int main()
{
    const size_t arraySize = 11;
    array<int,arraySize> s ;
    {48,55,78,21,66,100,22,44,82,77};

    cout<<"Grade distributuion:"<<endl;

    for(size_t i = 0;i<s.size();i++)
    {
        if(0 == i)
            cout<<"0-9:";
        else if(10 == i)
            cout<<"100:";
        else 
            cout<< i * 10<<"-"<<(i*10)+9<<":";

        for(unsigned int star = 0;star < s[i];star++)
            cout<<"*";

        cout<<endl;
    }
    // for(size_t i = 0;i<s.size();i++)
    //     s[i] = 2+2*i;

    // for(size_t j = 0;j<s.size();j++)
    //     cout << s[j]<<" ";


    return 0;
}

