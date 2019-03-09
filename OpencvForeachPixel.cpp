/****
 * opencv 遍历图像矩阵中的每个像素点
 * 
 * 三种方法汇总
 * 
 *****/
#include<iostream>
#include<array>
using namespace std;

int g_nValue = 80;
int g_nBias = 80;


//方法一：用指针访问像素
void Foreach_Pixel(Mat & inputImage,Mat & outputImage)
{
    //先将输入图像复制一份
    outputImage = inputImage.clone();//复制实参到临时变量
    int rowNumber = outputImage.rows;//行数
    int colNumber = outputImage.cols*outputImage.channels();//列数*通道数 = 每一行元素的个数

    for(int i=0;i<rowNumber;i++)
    {
        //获取第i行的首地址
        uchar* data = outputImage.ptr<uchar>(i);
        for(int j = 0;j<colNumber;j++)
        {
            data[j] = data[j]*(g_nValue * 0.01)+g_nBias;
        }
    }
}

//方法二：动态地址计算
//关于opencv 的基本数据类型：https://blog.csdn.net/maweifei/article/details/51227253
//typedef Vec<uchar,3> Vec3b 
//Vec<int,3>：表示的是int类型的和将向量模板类做实例化;n维列向量
//Vec3b:可以储存3个char字符型数据，用这样的数据去存储RGB图像中的一个像素点
void Foreach_Pixel(Mat &inputImage,Mat &outputImage)
{
    outputImage = inputImage.clone();
    int rowNumber = inputImage.rows;
    int colNumber = inputImage.cols;

    for(int i = 0;i<rowNumber;i++)
    {
        for(int j = 0;j<colNumber;j++)
        {
            outputNumber.at<Vec3b>(i,j)[0] = outputNumber.at<Vec3b>(i,j)[0]*(g_nValue*0.01)+g_nBias;//B
            outputNumber.at<Vec3b>(i,j)[1] = outputNumber.at<Vec3b>(i,j)[1]*(g_nValue*0.01)+g_nBias;//G
            outputNumber.at<Vec3b>(i,j)[2] = outputNumber.at<Vec3b>(i,j)[2]*(g_nValue*0.01)+g_nBias;//R
        }
    }
}



//方法三：迭代器的方式来遍历
void Foreach_Pixel(Mat &inputImage,Mat &outputImage)
{
    outputImage = InputImage.clone();

    //get the iterator
    Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
    Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();

    for(;it!=itend;it++)
    {
        (*it)[0] = (*it)[0]/50 + 20;
        (*it)[1] = (*it)[1]/50 + 20;
        (*it)[2] = (*it)[2]/50 + 20;        
    }


}
