#include<iostream>
#include<string>
using namespace std;
/*******Readme.md***********
 *leetcode初级算法汇总
 * 从字符串开始（前面的已经编过了不想再重新编一遍）
 * 有时间就再敲一次
 * 
 * auther:Skywalker
 * *****************/
#if 0 //有效的字母异位词
//20181212:https://leetcode-cn.com/explore/interview/card/top-interview-questions-easy/5/strings/35/
//遍历string字符串的方法：
//1.通过数组方式遍历
void forEach_one(string s){
    for(int i = 0;i<s.length();i++){
        cout<< s[i]<<endl;
    }
    cout<<endl;
}
//2.通过迭代器的方式遍历
void forEach_two(string s){
    for(string::iterator it = s.begin();it!=s.end();it++)
    {
        cout<< *it <<endl;
    }
}
//3.通过at()的方式遍历
void forEach_three(string s){
    for(int i = 0;i<s.length();i++){
        cout<<s.at(i)<<" "<<endl;
    }
    cout<< endl;
}
//打印数组中的元素
void print_array(int s[],int n,int &in_count){
    int count = 0;
    for(int i = 0;i<n;i++)
    {
        if(s[i]!=0)
        {
            count++;
            cout<< s[i] <<" ";
            continue;
        }
        cout<< s[i] <<" ";
    }
    in_count = count;
}

class Solution{
public:
    bool isAnagram(string s,string t){
        //先判断字符串是否存在
        int size_1 = s.size();
        int size_2 = t.size();
        if(size_1==0||size_2==0)
            return -1;
        
        //计算字符的个数
        int num_1[26]={0};
        int num_2[26]={0};
        for(int i = 0;i<size_1;i++){
            num_1[s[i]-'a']++;
        }
        for(int j = 0;j<size_2;j++){
            num_2[t[j]-'a']++;
        }

        int array_availble_1 = 0;
        int array_availble_2 = 0;

        print_array(num_1,26,array_availble_1);
        cout<<endl;
        print_array(num_2,26,array_availble_2);

        //确定数组是否有相同的数据
        if(array_availble_1!=array_availble_2)
            return false;
        bool arrayEqual = true;
        int count = 0;
        while(arrayEqual && count<size_1)
        {
            if(num_1[count]!= num_2[count])
                arrayEqual = false;
            count++;
        }
        if(arrayEqual)
        {
            cout<<"array is the same!";
            return true;
        }  
        else{
            cout<<"arrays is not the same!";
            return false;
        }

    }
};
#endif


int main()
{
    string s;
    string t;

    s = "a";
    t = "ab";

    Solution result;

    bool end;
    end = result.isAnagram(s,t);

    cout<<"end:"<<end<<endl;

    return 0;
}
