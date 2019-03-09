/*
 * @Author: Skywalker
 * @Date: 2018-12-07 15:08:05
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:11:18
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
using namespace std;

class Solution{
public:
    //整数反转
    int int_ver(int x){
        int res = 0;
        while(x!=0)
        {
            int middle = res * 10 + x % 10;
            if(middle/10 != res) return 0;
            res = middle;
            x /= 10;
        }
        return res;
    }

    //字符串中的第一个唯一字符
    int firstUniqChar(string s){
        int n = s.size();
        if(n==0)
            return -1;
        int a[26]={0};
        for(int i = 0;i<n;i++)
        {
            a[s[i]-'a']++;
        }
        for(int i = 0;i<n;i++)
        {
            if(a[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};


int main()
{
    string s = "loveleetcode";
    Solution a;
    int number;
    number = a.firstUniqChar(s);

    cout<<"number is:"<<number<<endl;

    return 0;
}