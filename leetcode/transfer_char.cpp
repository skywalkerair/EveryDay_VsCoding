/*
 * @Author: Skywalker
 * @Date: 2018-12-07 08:46:15
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:12:08
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
#include<string>
using namespace std;
void print_str(string &str);

class Solution{
public:
    string reverseString(string &s){
        print_str(s);
        cout<<endl;
        int len_string = s.size();
            for(int i = 0;i<len_string/2;i++)
                {
                    char a[] = {s[i]};
                    s[i] = s[len_string-1-i];
                    s[len_string-1-i] = a[0];
                }
        return s;
    }
    
};

void print_str(string &str)
{
    //TODO:为什么这样不能遍历
    int n = str.size();
    for(int i = 0;i<n;i++)
       cout<<str[i]<<" ";
    cout<<endl;
    // for(int i = 0;i<str.size();i++)
    //     cout<<str[i];
}

int main()
{
    string input="hello";
    Solution a;
    string b;
    b = a.reverseString(input);

   
    print_str(b);
    getchar();

    return 0;
}