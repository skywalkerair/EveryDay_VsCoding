/*
 * @Author: Skywalker
 * @Date: 2018-12-18 21:30:24
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:11:13
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    int myAtoi(string str){
        int n = str.size();
        int i;
        int flag = 0;
        long ans= 0;
        for(i = 0;i<n;i++)
        {
            if(flag == 0){
                if(str[i] == '+') flag = 1;
                else if(str[i] == '-') flag = -1;
                else if(str[i] == ' ') continue;
                else if(str[i] >= '0' && str[i] <= '9'){
                    ans = str[i] - '0';
                    flag = 1;
                }
                else return 0;
            }
            else{
                if(str[i]>='0'&&str[i]<='9')
                {
                    ans = ans*10+(str[i]-'0');
                    if(ans*flag < INT8_MIN) return INT8_MIN;
                    if(ans*flag > INT8_MAX) return INT8_MAX;
                }
                else if(ans!= 0) break;
                else return 0;
            }
        }
        return ans*flag;
    }

};