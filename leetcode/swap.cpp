/*
 * @Author: Skywalker
 * @Date: 2018-12-06 15:33:45
 * @LastEditors: Skwalker_last
 * @LastEditTime: 2018-12-22 20:12:05
 * @Description: file content
 * @Version: Version_1.0
 */
#include<iostream>
using namespace std;

//按值传递:将实参copy一份再传进来
int swap_1(int i,int j)
{
    int tmp = i;
    i = j;
    j = tmp;
    return i;
}
//按引用传递：直接将实参的值改变
void swap_2(int &i,int &j)
{
    int tmp = i;
    i = j;
    j = tmp;
}

/******参数为数组时，如何传值到函数中******
 * 这里传递的参数类型都是：int*。
 * 
 * **********************/
//1.1参数为数组的函数
// int FindMax(int* array){}
// int FindMax(int array[]){}
// int FindMax(int array[10]){}

/***********************1.1参数为数组引用的函数**********************/
//1.2参数为数组引用的函数======>要求形参和实参的个数必须匹配
//int FindMax(int(&array)[5]);
void print_0(int* x[3][3])
{
    x[1][1] = 0;
    // for(int i = 0;i<size;i++)
    //     cout<<x[i]<<" ";
    // cout<<endl;
}

void print_1(int x[],size_t size)
{
    x[1] = 8;
    // for(int i = 0;i<size;i++)
    //     cout<<x[i]<<" ";
    // cout<<endl;
}

void print_2(int x[5],size_t size)
{
    //x[1] = 8;
    for(int i = 0;i<size;i++)
        cout<<x[i]<<" ";
    cout<<endl;
}

/***********************2.1多维数组引用传递**********************/
void print_hhh(int (&x)[3][3])
{
    x[1][1] = 0;
    // for(int i = 0;i<5;i++)
    //         cout<<x[i]<<" ";
    //     cout<<endl;
}
/***********************2.1多维数组引用传递**********************/
//*x表示第0行，每一行有3个元素，一共row_size行
void print_lot(int (*x)[3],int row_size)
{
    x[1][1] = 10;
}


/***********************1.3传递字符数组**********************/
void print_char(char* x)
{
    while(*x != NULL)
        cout<<*x++;
    cout<<endl;
}


int main()
{
    //1.先验证一维的数组
    //看看能不能改变数组的值
    int input[3][3] = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    // print_0(input,5);
    // print_1(input,5);
    // print_2(input,5);
    print_lot(input,3);

    for(int i= 0;i<3;i++)
    for(int j = 0;j<3;j++)
    {
        cout<<input[i][j]<<" ";
    }

    //2.验证二维数组


    return 0;
}