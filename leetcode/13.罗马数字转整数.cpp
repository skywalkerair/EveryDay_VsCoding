/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 *
 * https://leetcode-cn.com/problems/roman-to-integer/description/
 *
 * algorithms
 * Easy (56.88%)
 * Total Accepted:    41.7K
 * Total Submissions: 73.3K
 * Testcase Example:  '"III"'
 *
 * 罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。
 * 
 * 字符          数值
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 * 
 * 例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V +
 * II 。
 * 
 * 通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数
 * 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：
 * 
 * 
 * I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
 * X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
 * C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
 * 
 * 
 * 给定一个罗马数字，将其转换成整数。输入确保在 1 到 3999 的范围内。
 * 
 * 示例 1:
 * 
 * 输入: "III"
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: "IV"
 * 输出: 4
 * 
 * 示例 3:
 * 
 * 输入: "IX"
 * 输出: 9
 * 
 * 示例 4:
 * 
 * 输入: "LVIII"
 * 输出: 58
 * 解释: L = 50, V= 5, III = 3.
 * 
 * 
 * 示例 5:
 * 
 * 输入: "MCMXCIV"
 * 输出: 1994
 * 解释: M = 1000, CM = 900, XC = 90, IV = 4.
 * 
 */
#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s)
    {
         //put every element in string to vector
        int len = s.length();
        int sum = 0;
        for(int i = 0;i<len;)
        {
            //Situation 1
            if((s[i]-73) == 0 )//When  I
            {
                if((s[i+1]-86) == 0)
                {
                    sum += 4;//V
                    i += 2;
                    continue;
                }
                else if((s[i+1]-88) == 0){//X
                    sum += 9;
                    i += 2;
                    continue;
                }
                else{
                    sum += 1;
                    i += 1;
                    continue;
                }
            } 
            else if((s[i]-88)==0){//when s[i] == X
                if((s[i+1]-76) == 0){//XL
                    sum += 40;
                    i += 2;
                    continue;
                }
                else if((s[i+1]-67) == 0){//XC
                    sum += 90;
                    i += 2;
                    continue;
                }
                else{
                    sum += 10;
                    i += 1;
                    continue;
                }
            }
            else if((s[i]-67)==0){//when s[i] == C
                if((s[i+1]-68) == 0){//D
                    sum += 400;
                    i += 2;
                    continue;
                }
                else if((s[i+1]-77) == 0){//M
                    sum += 900;
                    i += 2;
                    continue;
                }
                else{
                    sum += 100;
                    i += 1;
                    continue;
                }
            }
            else{//Nomal Way
                if((s[i]-86) == 0){//V
                    sum += 5;
                    i += 1;
                    continue;
                }
                else if((s[i]-76) == 0){//L
                    sum += 50;
                    i += 1;
                    continue;
                }
                else if((s[i]-68) == 0){//D
                    sum += 500;
                    i += 1;
                    continue;
                }
                else if((s[i]-77) == 0){//M
                    sum += 1000;
                    i += 1;
                    continue;
                }
                else{
                    continue;
                }
            }
        }
        return sum;

    }
};

// int main(){
//     Solution A;
//     int sum = 0;
//     sum = A.romanToInt("MCDLXXVI");
//     cout<< "sum:"<<sum<<endl;
//     return 0;    
// }

