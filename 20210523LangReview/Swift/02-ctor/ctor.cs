/*

[ expriment result ]
===
- it turns out that C# doesnt suppurt ctor inheritance
===
*/ 

using System;

namespace TS
{
    class Base
    {
        private int m_x;
        public Base(int x = 0)
        { this.m_x = x; }
    }

    class Derived: Base
    {}
    class TS
    {
        static void Main(string[] args)
        {
            Derived d1 = new Derived(1); // error out
            System.Console.WriteLine($"d1 {d1.ToString()}");

            Console.ReadLine();
        }
    }
}