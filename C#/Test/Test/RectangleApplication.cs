using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test
{
    class RectangleApplication
    {
        //成员变量
        double length;
        double width;
        //成员函数
        public void Acceptdetails()
        {
            length = 4.5;
            width = 3.5;
        }
        public double GetArea()
        {
            return length * width;
        }

        public void Display()
        {
            Console.WriteLine("Length:{0}",length);
            Console.WriteLine("Width:{0}", width);
            Console.WriteLine("Area:{0}",GetArea());
        }
    }
    class Swap
    {
        public void s(ref int a,ref int b)
        {
            int mid;
            mid = a;
            a = b;
            b = mid;
        }
    }
}
