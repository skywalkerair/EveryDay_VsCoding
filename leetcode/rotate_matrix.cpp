/*
 * @Author: Skywalker
 * @Date: 2018-12-06 14:20:30
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:11:40
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
#include<vector>
using namespace std;

int rotate_matrix(int (*array)[3],size_t n)
{
    for(int i = 0;i<n/2;i++)
        for(int j = i;j<n-1-i;j++)
        {
            int tmp = array[i][j];
            array[i][j]=array[n-1-j][i];
            array[n-1-j][i] = array[n-1-i][n-1-j];
            array[n-1-i][n-1-i] = array[j][n-1-i];
            array[j][n-1-i] = tmp;
        }
}


int main()
{
    int input[3][3]={
        {1,2,3},
        {4,5,6},
        {7,8,9},
    };

    //sizeof()输出的是整个数组所占的字节数，要求数组长度需要再除以数组的类型；例如int类型需要除以4
    

    rotate_matrix(input,3);

    for(int i = 0;i<3;i++)
    for(int j = 0;j<3;j++)
    {
        cout<<input[i][j]<<" ";
    }

    return 0;
}