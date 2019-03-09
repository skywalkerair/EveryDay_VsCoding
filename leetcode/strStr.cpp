/*
 * @Author: Skywalker
 * @Date: 2018-12-18 21:51:16
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:11:48
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    int strStr(string haystack,string needle){
        int len1 = haystack.size();
        int len2 = needle.size();
        if(len1<len2)
            return -1;
        if((len1 == 0 && len2 == 0)||len2 == 0)
            return 0;
        for(int i = 0;i<len1;i++){
            int k = i;
            int j = 0;
            while(j<len2){
                if(haystack[k] == needle[j])
                {
                    k++;
                    j++;
                }
                else 
                    break;
            }
            if(j == len2)
                return i;
        }
        return -1;
    }

};