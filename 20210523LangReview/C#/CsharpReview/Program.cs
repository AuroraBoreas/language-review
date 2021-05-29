using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CsharpReview
{
    class Program
    {
        class Base
        {
            private int m_x;
            public Base(int x = 0)
            { this.m_x = x; }
        }

        class Derived : Base
        {

        }

        static void Main(string[] args)
        {
            Derived d1 = new Derived(1);
            System.Console.WriteLine($"d1 {d1.ToString()}");

            Console.ReadLine();
        }
    }
}
