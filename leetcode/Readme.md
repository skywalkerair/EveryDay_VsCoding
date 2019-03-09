### leetcode C++ 刷题总结

~~~13
13.罗马
(1) 在比较两个字符串时不能利用符号“==”，“==”符号比较的是两个字符串的地址是否相等。
(2) 若是比较两个字符，则可以用”==”直接进行比较~
(3) 但在比较两个string对象时是可以利用“==”的，相等的话，则表达式的返回值为1，不等为0。
====
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

====

~~~

