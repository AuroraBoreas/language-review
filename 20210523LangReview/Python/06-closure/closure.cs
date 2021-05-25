/*

a simple module demonstrates closure mechnsim in C#

@ZL, 20210525

[ expriment result ]
- by default, C# does not support exactly same behavior (access local variable) like swift
- by default, C# inner scope reads an object in outer space only;
- C# inner can not write or re-bind the object;
*/ 
using System;

namespace TS
{
    class TS 
    {
        static void Main(string[] args)
        {
            Func<int> f = Outer(1);

            Console.WriteLine($"1st call, {0}", f());
            Console.WriteLine($"2nd call, {0}", f());
            Console.WriteLine($"3rd call, {0}", f());

            Console.ReadLine();
        }

        static Func<int> Outer(int n)
        {
            int total = 0;
            int Inner()
            {
                total += n;
                return total;
            }
            return inner;
        }
    }
}