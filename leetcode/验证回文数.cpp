/******
 * 验证回文字符串
    给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

    说明：本题中，我们将空字符串定义为有效的回文串。

    示例 1:

    输入: "A man, a plan, a canal: Panama"
    输出: true
    示例 2:

    输入: "race a car"
    输出: false
*/

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
public:
    bool isPalindrome(string & s){
      if(s.length()==1)
            return 1;
        transform(s.begin(),s.end(),s.begin(),::tolower);        //转换成小写
        int i=0,j=s.length()-1;
        while(i<j)
        {
            for(;i<j;i++)                         //前标志一直跳过直到它是字符或数字为止
            {
                if((s[i]>='a'&&s[i]<='z') || (s[i]>='0'&&s[i]<='9'))
                    break;
            }
            for(;i<j;j--)                         //后标志一直跳过直到它是字符或数字为止
            {
                if((s[j]>='a'&&s[j]<='z')  || (s[j]>='0'&&s[j]<='9'))
                    break;
            }
            if( (s[i]-'a')%32==(s[j]-'a')%32)     //判断前标志和后标志是否相等
            {
                i++;                             //如果相等执行下一个循环
                j--;
            }
            else
                return 0;                         //如果不相等，直接返回false
        }
        return 1;                               //循环后都没问题的话，则证明是对的，返回true
    }
};

int main()
{
    string s;
    string t;
    string a;

    s = "A man, a plan, a canal: Panama";
    t = "race a car";
    a = "";

    Solution isPal;

    bool result;
    result = isPal.isPalindrome(t);
    cout << "result:"<<result<<endl;
    
    return 0;
}
