using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Test
{
    class HelloWorld
    {
        static void Main(string[] args)
        {
            /*My first C sharp coding*/
            Console.WriteLine("Hello World!");
            Console.ReadKey();

            RectangleApplication r = new RectangleApplication();
            r.Acceptdetails();
            r.Display();
            Console.ReadLine();

            int a = 1;
            int b = 2;

            Swap swap = new Swap();
            swap.s(ref a,ref b);
            Console.WriteLine("a:{0};b:{1}.",a,b);
            Console.ReadLine();

        }
    }
}
